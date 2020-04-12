#ifndef BASIC_RGB_STRIP_FADER
#define BASIC_RGB_STRIP_FADER

#include <stdlib.h>
#include <stdio.h>


struct RGB_UNIT{
    unsigned char r = 0;
    unsigned char g = 0;
    unsigned char b = 0;
};

struct RGB_STRIP_SECTION{
    RGB_UNIT rgb;
    unsigned char percentage;
};

void fadeStrip(RGB_STRIP_SECTION* _sections,int _num,RGB_UNIT* _strip ,int _len);

#endif