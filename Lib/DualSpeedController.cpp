#ifndef DUALSPEED_3223
#define DUALSPEED_3223

#include "DualSpeedController.h"

DualSpeedController::DualSpeedController(SpeedController *motor1,SpeedController *motor2)
{
    mot1 = motor1;
    mot2 = motor2;
}

DualSpeedController::~DualSpeedController()
{
    delete mot1;
    delete mot2;
}

void DualSpeedController::Set(float speed,uint8_t syncGroup)
{
    mot1->Set(speed,syncGroup);
    mot2->Set(speed,syncGroup);
}

float DualSpeedController::Get()
{
    return ((mot1->Get())+(mot2->Get()))/2;
}

void DualSpeedController::Disable()
{
    mot1->Disable();
    mot2->Disable();
}

void DualSpeedController::PIDWrite(float output)
{
    mot1->PIDWrite(output);
    mot1->PIDWrite(output);
}

#endif
