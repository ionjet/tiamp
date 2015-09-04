/* 
 * File:   PipeWatcher.cpp
 * Author: avasilyev
 * 
 * Created on August 27, 2015, 9:13 AM
 * refer to http://stackoverflow.com/questions/15055065/o-rdwr-on-named-pipes-with-poll
 */

#include "PipeWatcher.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>


#define PIPE_BUF 64

PipeWatcher::PipeWatcher() {
}

PipeWatcher::~PipeWatcher() {
}

int PipeWatcher::init() {
    file_handlers.clear();
}

int PipeWatcher::dispose() {

}

int PipeWatcher::addWatch(FileEventHandler* handler) {
    mkfifo(handler->getName().data(), 0666);
    file_handlers[handler->getName()] = handler;
}

int PipeWatcher::watch() {
    int fd;
    size_t len;
    char buf[PIPE_BUF];


    std::map<int, FileEventHandler *> handlers;
    std::vector<struct pollfd> polls(file_handlers.size());

    while (1) {

        int polls_num = 0;
        polls.clear();
        handlers.clear();
        // open pipes
        for (std::map<std::string, FileEventHandler *>::iterator
            it = file_handlers.begin(); it != file_handlers.end(); ++it) {

            struct pollfd pfd;
            pfd.events = POLLIN;
            fd = pfd.fd = open(it->first.data(), O_RDONLY | O_NONBLOCK);
            if (fd < 0) {
                // TODO: handle pipe open error
            } else {
                polls[polls_num++] = pfd;
                handlers[fd] = it->second;
            }
        }
        // poll the changes
        int ret_poll = poll(&polls[0], polls_num, 50);
        for (int i = 0; i < polls_num; i++) {
            if (polls[i].revents & POLLIN) {
                FileEventHandler * handler = handlers[polls[i].fd];
                handler->modified(polls[i].fd);
            }
        }
        // close pipes
        for (int i = 0; i < polls_num; i++) {
            close(polls[i].fd);
        }
    }
}