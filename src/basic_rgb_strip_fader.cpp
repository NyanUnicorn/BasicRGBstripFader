#include "basic_rgb_strip_fader.h"

void fadeStrip(RGB_STRIP_SECTION* _sections,int _num,RGB_UNIT* _strip ,int _len){
    int count = 0, delta = 0, upperUnitsInSection = 0, unitsInSection = 0, cumulUpperLen = 0;

    for(int s = 0; s < _num; s++){
        _strip[count].r += (_sections[s].rgb.r * (100 - delta)) / 100;
        _strip[count].g += (_sections[s].rgb.g * (100 - delta)) / 100;
        _strip[count].b += (_sections[s].rgb.b * (100 - delta)) / 100;
        ++count;
        upperUnitsInSection = _len * _sections[s].percentage;
        cumulUpperLen += upperUnitsInSection;
        unitsInSection = upperUnitsInSection / 100;
        delta = cumulUpperLen - (cumulUpperLen / 100) * 100;
        for(int u = 1; u < unitsInSection; ++u){
            _strip[count].r = _sections[s].rgb.r;
            _strip[count].g = _sections[s].rgb.g;
            _strip[count].b = _sections[s].rgb.b;
            ++count;
        }
        if(count < _len & delta != 0){
            _strip[count].r = (_sections[s].rgb.r * delta) / 100;
            _strip[count].g = (_sections[s].rgb.g * delta) / 100;
            _strip[count].b = (_sections[s].rgb.b * delta) / 100;
        }
    }
}