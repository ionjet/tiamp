/* 
 * File:   FileEventHandler.h
 * Author: avasilyev
 *
 * Created on August 21, 2015, 2:13 PM
 */

#ifndef FILEEVENTHANDLER_H
#define	FILEEVENTHANDLER_H

#include <iostream>
#include <string>
using namespace std;

class FileEventHandler {
public:

    FileEventHandler(string name) {
        this->name = name;        
    }

    virtual int accessed() {
        std::cout << "FileEventHandler::accessed " << name << endl;
        return 0;
    }

    virtual int created() {
        std::cout << "FileEventHandler::created " << name << endl;
        return 0;
    }

    virtual int modified() {
        std::cout << "FileEventHandler::modified " << name << endl;
        return 0;
    }

    virtual int modified(int fd) {
        std::cout << "FileEventHandler::modified " << name << " descriptor " << fd << endl;
        return 0;
    }

    virtual int deleted() {
        std::cout << "FileEventHandler::deleted " << name << endl;
        return 0;
    }

    string getName() {
        return name;
    }
    void setFolder(string folder) {
        this->folder = folder;
    }
protected:
    string folder;
    string name;    
};



#endif	/* FILEEVENTHANDLER_H */

