#include "CatapultSubsystem.h"
#include "../Commands/Catapult/CatapultSetCommand.h"

CatapultSubsystem::CatapultSubsystem() :
    Subsystem("CatapultSubsystem")
{
    forward1Solenoid = new Solenoid(CATAPULT_MODULE,CATAPULT_1_FORWARD_CHANNEL); // Prime
    reverse1Solenoid = new Solenoid(CATAPULT_MODULE,CATAPULT_1_REVERSE_CHANNEL); // Retract
    forward2Solenoid = new Solenoid(CATAPULT_MODULE,CATAPULT_2_FORWARD_CHANNEL); // Lock
    reverse2Solenoid = new Solenoid(CATAPULT_MODULE,CATAPULT_2_REVERSE_CHANNEL); // Fire
}

void CatapultSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new CatapultSetCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// For ifs with type: since big is 1 and little is 0, I can do type ? foo : bar; and have foo do cylinder group 1 and bar do group 2.
void CatapultSubsystem::Set(CatapultSubsystem::CylinderType type,Relay::Value value)
{
    switch (value)
    {
        case false:
            printf("Attempted to set catapult motors to just off.\n");
            break;
        case true:
            printf("Attempted to set catapult motors to just on.\n");
            break;
        case Relay::kForward:
            if (type)
            {
                reverse2Solenoid->Set(false);
                forward2Solenoid->Set(true);
            } else
            {
                reverse1Solenoid->Set(false);
                forward1Solenoid->Set(true);
            }
            break;
        case Relay::kReverse:
            if (type)
            {
                forward2Solenoid->Set(false);
                reverse2Solenoid->Set(true);
            } else
            {
                forward1Solenoid->Set(false);
                reverse1Solenoid->Set(true);
            }
            break;
    }
}
