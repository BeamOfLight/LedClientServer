#ifndef LED_H
#define LED_H

#include <string>
#include <sstream>
#include <stdlib.h>     /* atoi */

using namespace std;

enum LedColor {COLOR_RED, COLOR_GREEN, COLOR_BLUE};

class Led
{
    bool state;
    LedColor color;
    unsigned char rate;

  public:
    Led();
    bool getState();
    string getStateText();
    void setState(bool state);
    void setState(string state_str);
    LedColor getColor();
    string getColorText();
    void setColor(LedColor color);
    void setColor(string color_str);
    unsigned char getRate();
    void setRate(unsigned char rate);
    void setRate(string rate_text);
    string getInfo();
};

#endif
