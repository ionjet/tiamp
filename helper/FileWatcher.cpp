/* 
 * File:   FileWatcher.cpp
 * Author: avasilyev
 * 
 * Created on August 21, 2015, 2:58 PM
 */

#include <sys/types.h>
#include <sys/inotify.h>
#include <poll.h>
#include <sys/types.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "FileWatcher.h"

FileWatcher::FileWatcher(std::string folder) {
    notify_fd = 0;
    this->folder = folder;
}

FileWatcher::FileWatcher(const FileWatcher& orig) {
}

FileWatcher::~FileWatcher() {
    dispose();
}

int FileWatcher::init() {
    if (!notify_fd) {
        notify_fd = inotify_init();
        if (notify_fd < 0) {
            fprintf(stderr, "inotify init failed: %s\n", strerror(errno));
            return -1;
        }
        int wd = inotify_add_watch(notify_fd, folder.data(), IN_MODIFY /*| IN_CREATE | IN_DELETE*/);
        file_watches.push_front(wd);
    }
}

int FileWatcher::dispose() {
    std::list<int>::iterator it;
    for (it = file_watches.begin(); it != file_watches.end(); it++) {
        (void) inotify_rm_watch(notify_fd, *it);
    }
    file_watches.clear();
    if (!notify_fd) {
        (void) close(notify_fd);
        notify_fd = 0;
    }
}

int FileWatcher::addWatch(FileEventHandler *handler) {
    file_handlers[handler->getName()] = handler;    
    handler->setFolder(folder);
}

int FileWatcher::watch() {

    int length;
    int i = 0;
    char buffer[BUF_LEN];

    while (1) {

        struct pollfd pfd = {notify_fd, POLLIN, 0};
        int ret_poll = poll(&pfd, 1, 50); // timeout of 50ms

        if (ret_poll < 0) {
            fprintf(stderr, "poll failed: %s\n", strerror(errno));
        } else if (ret_poll == 0) {
            // Timeout with no events, move on.
        } else {
            length = read(notify_fd, buffer, BUF_LEN);

            if (length < 0) {
                fprintf(stderr, "inotify read failed: %s\n", strerror(errno));
            }

            while (i < length) {
                struct inotify_event *event =
                        (struct inotify_event *) &buffer[i];
                if (event->len) {
                    if (file_handlers.find(event->name) != file_handlers.end()) {
                        FileEventHandler *handler = file_handlers[event->name];

                        if (event->mask & IN_ACCESS) {
                            handler->accessed();
                        } else if (event->mask & IN_MODIFY) {
                            handler->modified();
                        } else if (event->mask & IN_IGNORED) {
                            // the watch reset must be done ?
                        } else if (event->mask & IN_CREATE) {
                            handler->created();
                        } else if (event->mask & (IN_DELETE | IN_DELETE_SELF)) {
                            handler->deleted();
                        }
                    }
                }
                i += EVENT_SIZE + event->len;
            }
            i = 0;
        }
    }

}