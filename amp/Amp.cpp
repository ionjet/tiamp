/* 
 * File:   Amp.cpp
 * Author: avasilyev
 * 
 * Created on August 21, 2015, 2:35 PM
 */

#include "Amp.h"

Amp::Amp(TAS5548 *modulator) {
    this->modulator = modulator;
}

Amp::~Amp() {
}


int Amp::setVolume(float volume, VolumeType type) {
    switch(type){
        case DB:
            // TODO: convert to 5548's representation
            modulator->setVolume((int)volume);
            break;
        case PERCENT:
            // TODO: convert to 5548's representation
            modulator->setVolume((int)volume);
            break;
    }
}


