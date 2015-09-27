#include "Led.h"

Led::Led()
{
    state = false;
    color = COLOR_RED;
    rate = 0;
}

bool Led::getState()
{
    return state;
}

std::string Led::getStateText()
{
    std::string state_text = "off";
    if (getState())    {
        state_text = "on";
    }

    return state_text;
}

void Led::setState(bool state)
{
    this->state = state;
}

void Led::setState(std::string state_str)
{
    if (state_str == "on") {
        state = true;
    } else if (state_str == "off") {
        state = false;
    }
}

LedColor Led::getColor()
{
    return color;
}

std::string Led::getColorText()
{
    std::string result;
    if (this->color == COLOR_RED) {
        result = "red";
    } else if (this->color == COLOR_GREEN) {
        result = "green";
    } else if (this->color == COLOR_BLUE) {
        result = "blue";
    }

    return result;
}

void Led::setColor(LedColor color)
{
    this->color = color;
}

void Led::setColor(std::string color_str)
{
    if (color_str == "red") {
        this->color = COLOR_RED;
    } else if (color_str == "green") {
        this->color = COLOR_GREEN;
    } else if (color_str == "blue")    {
        this->color = COLOR_BLUE;
    }
}

unsigned char Led::getRate()
{
    return rate;
}

void Led::setRate(unsigned char rate)
{
    this->rate = rate;
}

void Led::setRate(std::string rate_text)
{
    rate = atoi(rate_text.c_str());
}

std::string Led::getInfo()
{
    std::ostringstream result;
    result << "State: " << getStateText() << "\tColor: " << getColorText() << "\tRate: " << (int) getRate() << " Hz";

    return result.str();
}
