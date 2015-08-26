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
        std::cout << "FileEventHandler::accessed " << name << "\n";
        return 0;
    }

    virtual int created() {
        std::cout << "FileEventHandler::created " << name << "\n";
        return 0;
    }

    virtual int modified() {
        std::cout << "FileEventHandler::modified " << name << "\n";
        return 0;
    }

    virtual int deleted() {
        std::cout << "FileEventHandler::deleted " << name << "\n";
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

