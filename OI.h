#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "Robotmagic.h"

class OI
{
private:
public:
    OI();

#define JOYSTICK_main_TYPE xbox
    SENSOR_OI_H(joystick,main);

    SENSOR_OI_H(gyro,gyro);
    SENSOR_OI_H(digitalin,compressor);
    SENSOR_OI_H(digitalin,arm_top);
    SENSOR_OI_H(digitalin,arm_bot);
    SENSOR_OI_H(digitalin,catapult);
    SENSOR_OI_H(encoder,drive_left);
    SENSOR_OI_H(encoder,drive_right);
};

#endif
