/* 
 * File:   Amp.h
 * Author: avasilyev
 *
 * Created on August 21, 2015, 2:35 PM
 */

#ifndef AMP_H
#define	AMP_H

#include <list>
//#include <bcm2835.h>
#include "../hw/TAS5548.h"
#include "../hw/TAS5631B.h"

enum VolumeType {
    PERCENT, DB
};

class Amp {
public:
    Amp(TAS5548 *modulator);    
    virtual ~Amp();

    int setVolume(float volume, VolumeType type);
protected:
    TAS5548 *modulator;
    std::list<TAS5631B *> amplifiers;
private:

};

#endif	/* AMP_H */

