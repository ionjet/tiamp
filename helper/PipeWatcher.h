/* 
 * File:   PipeWatcher.h
 * Author: avasilyev
 *
 * Created on August 27, 2015, 9:13 AM
 */

#ifndef PIPEWATCHER_H
#define	PIPEWATCHER_H

#include <map>
#include <vector>
#include <string>
#include "FileEventHandler.h"
#include "Watcher.h"

class PipeWatcher {
    std::map<std::string, FileEventHandler *> file_handlers;
    
public:
    PipeWatcher();    
    virtual ~PipeWatcher();
    
    int addWatch(FileEventHandler *);
    int init();
    int watch();
    int dispose();
private:

};

#endif	/* PIPEWATCHER_H */

