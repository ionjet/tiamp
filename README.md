# tiamp
[json-org]: http://json.org/
[jsoncpp]: https://github.com/open-source-parsers/jsoncpp/
[bcm2835]: http://www.airspayce.com/mikem/bcm2835/
[RPi]: https://www.raspberrypi.org/
[tas5548]: http://www.ti.com/product/tas5548
[tas5631b]: http://www.ti.com/product/tas5631b
[usbstreamer]: http://www.minidsp.com/products/usb-audio-interface/usbstreamer
[tinod]: https://github.com/gitstrah/tinod

[RPi2][RPi] [TAS5548][tas5548]+[TAS5631B][tas5631b] amplifier control application.
Linux/C++
Intended to be used as a hardware abstraction layer by [tinod][tinod]

NetBeans project included

## Dependencies


### bcm2835 gpio library
[bcm2835 gpio library][bcm2835] by Mike McCauley


### JsonCpp
[jsoncpp][jsoncpp]
read jsoncpp readme first.
run amalgamate.py

NetBeans: clone jsoncpp repo as a sibling of tiamp, NetBeans project already has them referenced.


## The idea

```
+-------------------------------+                            
|          Raspberry Pi         |                            
|                               |     +----------+           
|    +-----+                    |     |          |           
|    |     +--------------------------> USB+>I2S +----+      
|    | MPD |                    |     |          |    |      
|    |     <-----------+        |     +----------+    |      
|    +-----+           |        |                     |      
|                  +---v---+    |               +-----v-----+
|                  |       |    |   +----------->  TAS5548  |
|       +----------> tinod |    |   |           |    PWM    |
|       |          |       |    |   |    +------+ Modulator |
|       |          +-------+    |   |    |      +-----+-----+
|       |                       |   |    |            |      
|   +---v---+                   |   |    |            |      
|   |       +-------I2C-------------+    |            |      
|   | tiamp |                   |        |      +-----v-----+
|   |       <-------status---------------+      |  TAS5631B |
|   +---^---+                   |               |   Power   |
|       |                       |               |   Stage   |
+-------------------------------+               +-----+-----+
        |                                             |      
        +------------status---------------------------+      

```
