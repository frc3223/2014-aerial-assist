#include "CatapultSubsystem.h"

CatapultSubsystem::CatapultSubsystem() :
    Subsystem("CatapultSubsystem")
{
    forward1Relay = new Relay(CATAPULT_MODULE,CATAPULT_1_FORWARD_CHANNEL,Relay::kForwardOnly); // Prime
    reverse1Relay = new Relay(CATAPULT_MODULE,CATAPULT_1_REVERSE_CHANNEL,Relay::kForwardOnly); // Retract
    forward2Relay = new Relay(CATAPULT_MODULE,CATAPULT_2_FORWARD_CHANNEL,Relay::kForwardOnly); // Lock
    reverse2Relay = new Relay(CATAPULT_MODULE,CATAPULT_2_REVERSE_CHANNEL,Relay::kForwardOnly); // Fire
}

void CatapultSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

Relay::Value CatapultSubsystem::Get(Relay::Value value,int number)
{
    number -= 1;
    switch (value)
    {
        case Relay::kForward:
            return number ? forward2Relay->Get() : forward1Relay->Get();
            break;
        case Relay::kReverse:
            return number ? reverse2Relay->Get() : reverse2Relay->Get();
            break;
        case Relay::kOff:
            printf("Attempted get of catapult relay %d Off.\n",number+1);
            return Relay::kOff;
            break;
        case Relay::kOn:
            printf("Attempted get of catapult relay %d On.\n",number+1);
            return Relay::kOff;
            break;
    }
    return Relay::kOff; // This is to stop your compiler from complaining about "control reaches end of non-void function".
    // Thatt would happen because there's no unconditional return.
    // It isn't a problem because all cases are covered in the type.
}

void CatapultSubsystem::Set(Relay::Value value,int number)
{
    number -= 1;
    switch (value)
    {
        case Relay::kOff:
            forward1Relay->Set(Relay::kOff);
            reverse1Relay->Set(Relay::kOff);
            forward2Relay->Set(Relay::kOff);
            reverse2Relay->Set(Relay::kOff);
            break;
        case Relay::kOn:
            printf("Attempted to set both catapult motors to on.\n");
            break;
        case Relay::kForward:
            if (number)
            {
                forward2Relay->Set(Relay::kOn);
                reverse2Relay->Set(Relay::kOff);
            } else
            {
                forward1Relay->Set(Relay::kOn);
                reverse1Relay->Set(Relay::kOff);
            }
            break;
        case Relay::kReverse:
            if (number)
            {
                forward2Relay->Set(Relay::kOff);
                reverse2Relay->Set(Relay::kOn);
            } else
            {
                forward1Relay->Set(Relay::kOff);
                reverse1Relay->Set(Relay::kOn);
            }
            break;
    }
}
