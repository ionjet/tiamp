/* 
 * File:   Watcher.h
 * Author: avasilyev
 *
 * Created on August 27, 2015, 9:20 AM
 */

#ifndef WATCHER_H
#define	WATCHER_H

#include "FileEventHandler.h"


class Watcher {
public:
    virtual int addWatch(FileEventHandler *) = 0;
    virtual int init() = 0;
    virtual int watch() = 0;
    virtual int dispose() = 0;    
};

#endif	/* WATCHER_H */

