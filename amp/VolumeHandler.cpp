/* 
 * File:   VolumeHandler.cpp
 * Author: avasilyev
 * 
 * Created on August 21, 2015, 2:21 PM
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "VolumeHandler.h"
#include "../helper/FileEventHandler.h"

#define BUF 50

VolumeHandler::VolumeHandler(std::string name, Amp * amp) : FileEventHandler(name) {
    this->amp = amp;
}

// assuming we are watching a pipe
int VolumeHandler::modified(int fd) {
    char  buf[BUF];
    int len = read(fd, &buf, BUF);                
    
    std::cout << "VolumeHandler::modified: " << strtod(buf, NULL) << endl;
    // TODO: convert to float and call setVolume()
    // TODO: set global configuration object property(es), save JSON
    return 0;
}