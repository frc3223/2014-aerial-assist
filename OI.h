#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Robotmap.h"

class OI {
private:
public:
    OI();
    JOYSTICK_H
    JoystickButton *button1;
    JoystickButton *button2;
    JoystickButton *button3;
    JoystickButton *button4;
    JoystickButton *button5;
    JoystickButton *button6;
    JoystickButton *button7;
    JoystickButton *button8;
    JoystickButton *button9;
    JoystickButton *button0;
    
    JoystickButton *buttonSlow;
};

#endif
