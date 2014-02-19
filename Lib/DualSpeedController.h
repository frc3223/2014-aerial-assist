#ifndef DUALSPEED_3223_H
#define DUALSPEED_3223_H

#include "WPILib.h"

class DualSpeedController: public SpeedController
{
public:
    DualSpeedController(SpeedController *motor1,SpeedController *motor2);
    virtual ~DualSpeedController();
    virtual void Set(float value,uint8_t syncGroup = 0);
    virtual float Get();
    virtual void Disable();

    virtual void PIDWrite(float output);

private:
    SpeedController *mot1;
    SpeedController *mot2;
};

#endif
