#include "CatapultSubsystem.h"
#include "../Robotmap.h"

CatapultSubsystem::CatapultSubsystem() :
    Subsystem("CatapultSubsystem")
{
    forwardRelay = new Relay(CATAPULT_MODULE,CATAPULT_FORWARDRELAY,Relay::kForwardOnly);
    reverseRelay = new Relay(CATAPULT_MODULE,CATAPULT_REVERSERELAY,Relay::kForwardOnly);
}

void CatapultSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

Relay::Value CatapultSubsystem::Get(Relay::Value value)
{
    switch (value)
    {
        case Relay::kForward:
            return forwardRelay->Get();
            break;
        case Relay::kReverse:
            return reverseRelay->Get();
            break;
        case Relay::kOff:
            printf("Attempted get of catapult motor Off.\n");
            return Relay::kOff;
            break;
        case Relay::kOn:
            printf("Attempted get of catapult relay On.\n");
            return Relay::kOff;
            break;
    }
    return Relay::kOff;  // This is to stop your compiler from complaining about "control reaches end of non-void function".
    // Thatt would happen because there's no unconditional return.
    // It isn't a problem because all cases are covered in the type.
}

void CatapultSubsystem::Set(Relay::Value value)
{
    switch (value)
    {
        case Relay::kOff:
            forwardRelay->Set(Relay::kOff);
            reverseRelay->Set(Relay::kOff);
            break;
        case Relay::kOn:
            printf("Attempted to set both catapult motors to on.\n");
            break;
        case Relay::kForward:
            forwardRelay->Set(Relay::kOn);
            reverseRelay->Set(Relay::kOff);
            break;
        case Relay::kReverse:
            forwardRelay->Set(Relay::kOff);
            reverseRelay->Set(Relay::kOn);
            break;
    }
}
