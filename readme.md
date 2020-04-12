# Simple RGB strip fader
This is a little c++ library to create smother trasitions between rgb leds on a strip.

## Description
It is designed for an arduino project, it is minimal, has little security checks and avoids floating point numbers.

## Usage
 ```
#include "basic_rgb_strip_fader.h"

#define STRIP_LENGTH 20 \\ length of led strip ; can also be set in runtime
```
inside method:
 ```
    RGB_UNIT strip[STRIP_LENGTH];

    RGB_STRIP_SECTION sections[3];
    sections[0].percentage = 53;
    sections[0].rgb.r = 255;
    sections[1].percentage = 43;
    sections[1].rgb.b = 255;
    sections[2].percentage = 4;

    fadeStrip(sections,3,strip,STRIP_LENGTH);
```
example output from printf("{%i,%i,%i}", strip[i].r , strip[i].g , strip[i].b );

```
{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{255,0,0}{153,0,102}{0,0,255}{0,0,255}{0,0,255}{0,0,255}{0,0,255}{0,0,255}{0,0,255}{0,0,51}{0,0,0}
```
