/* 
 * File:   TAS5548.h
 * Author: avasilyev
 *
 * Created on August 21, 2015, 2:38 PM
 */

#ifndef TAS5548_H
#define	TAS5548_H

class TAS5548 {
public:
    TAS5548();
    virtual ~TAS5548();
    // 5548 specifics:
    
    int setVolume(int volume);

protected:    
    
private:

};

#endif	/* TAS5548_H */

