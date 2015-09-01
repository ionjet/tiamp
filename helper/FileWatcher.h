/* 
 * File:   FileWatcher.h
 * Author: avasilyev
 *
 * Created on August 21, 2015, 2:58 PM
 */

#ifndef FILEWATCHER_H
#define	FILEWATCHER_H

#include <map>
#include <list>
#include <string>
#include "FileEventHandler.h"
#include "Watcher.h"


#define EVENT_SIZE  (sizeof(struct inotify_event))
#define BUF_LEN     (1024 * (EVENT_SIZE + 16))


class FileWatcher : public Watcher {
public:
    FileWatcher(std::string folder);
    FileWatcher(const FileWatcher& orig);
    virtual ~FileWatcher();
    int addWatch(FileEventHandler *);
    int init();
    int watch();
    int dispose();
protected:
    
private:
    std::string folder;
    int notify_fd;
    std::map<std::string, FileEventHandler *> file_handlers;
    std::list<int> file_watches;
};

#endif	/* FILEWATCHER_H */

