#ifndef LED_H
#define LED_H

#include <string>
#include <sstream>
#include <stdlib.h>     /* atoi */

enum LedColor {COLOR_RED, COLOR_GREEN, COLOR_BLUE};

class Led
{
    bool state;
    LedColor color;
    unsigned char rate;

  public:
    Led();
    bool getState();
    std::string getStateText();
    void setState(bool state);
    void setState(std::string state_str);
    LedColor getColor();
    std::string getColorText();
    void setColor(LedColor color);
    void setColor(std::string color_str);
    unsigned char getRate();
    void setRate(unsigned char rate);
    void setRate(std::string rate_text);
    std::string getInfo();
};

#endif
