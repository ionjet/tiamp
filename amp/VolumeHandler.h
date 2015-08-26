/* 
 * File:   VolumeHandler.h
 * Author: avasilyev
 *
 * Created on August 21, 2015, 2:21 PM
 */

#ifndef VOLUMEHANDLER_H
#define	VOLUMEHANDLER_H

#include <cstdlib>
#include "../helper/FileEventHandler.h"
#include "Amp.h"


class VolumeHandler: public FileEventHandler {
public:
    VolumeHandler(std::string name, Amp * amp);
    
    virtual int modified();
    
protected:
    int setVolume(float volume);    
private:
    Amp *amp;
};

#endif	/* VOLUMEHANDLER_H */
