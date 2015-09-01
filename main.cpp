/* 
 * File:   main.cpp
 * Author: avasilyev
 *
 * Created on August 21, 2015, 1:32 PM
 */

#include <cstdlib>
//#include <bcm2835.h>
#include <unistd.h>
#include <iostream>
#include <stdio.h>

#include "helper/FileWatcher.h"
#include "amp/VolumeHandler.h"
#include "helper/PipeWatcher.h"
#include <fcntl.h>
#include <unistd.h>
#include <poll.h>
#include <sys/stat.h>

#define PIPE_BUF 64

using namespace std;

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

/*
 * 
 */
int main(int argc, char** argv) {
    printf("Welcome ...\n");

    VolumeHandler *volume1 = new VolumeHandler("/tmp/vol", NULL);
    
    PipeWatcher *pw = new PipeWatcher();
    pw->init();
    pw->addWatch(volume1);
    pw->watch();
    
    exit(0);    
}

