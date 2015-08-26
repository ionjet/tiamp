/* 
 * File:   main.cpp
 * Author: avasilyev
 *
 * Created on August 21, 2015, 1:32 PM
 */

#include <cstdlib>
#include <bcm2835.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "helper/FileWatcher.h"
#include "amp/VolumeHandler.h"

using namespace std;

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

/*
 * 
 */
int main(int argc, char** argv) {
    printf("Welcome ...\n");
    
    VolumeHandler *hVolume = new VolumeHandler("vol", NULL);
    
    FileWatcher *w = new FileWatcher("/tmp");
    w->init();
    w->addWatch(hVolume);
    w->watch();
    
    
    
    printf("Welcome ...\n");
    if (!bcm2835_init())
	return 1;
    
        // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (1)
    {
	// Turn it on
	bcm2835_gpio_write(PIN, HIGH);
	
	// wait a bit
	bcm2835_delay(500);
	
	// turn it off
	bcm2835_gpio_write(PIN, LOW);
	
	// wait a bit
	bcm2835_delay(1000);
        cout << "blink!";
    }
    bcm2835_close();
    return 0;
        
}

