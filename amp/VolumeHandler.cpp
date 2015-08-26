/* 
 * File:   VolumeHandler.cpp
 * Author: avasilyev
 * 
 * Created on August 21, 2015, 2:21 PM
 */

#include <iostream>
#include <fstream>
#include "VolumeHandler.h"
#include "../helper/FileEventHandler.h"

VolumeHandler::VolumeHandler(std::string name, Amp * amp) : FileEventHandler(name) {
    this->amp = amp;
}

int VolumeHandler::modified() {
    std::cout << "VolumeHandler::modified ";
    std::string file = folder + "/" + name;
    std::ifstream myfile(file.data());
    std::string line;
    if (myfile.is_open()) {
        if (getline(myfile, line)) {
            std::cout << line << "\n";
            // TODO: convert to float and call setVolume()
        } else {
            std::cout << "<<EMPTY>>\n";
        }
        myfile.close();
    } else {
        std::cout << "<<can't open " << file << ">>\n";
    }
}