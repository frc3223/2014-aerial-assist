#include "ArmSubsystem.h"
#include "../Commands/Arm/UpCommand.h"

ArmSubsystem::ArmSubsystem() :
    Subsystem("ArmSubsystem")
{
    arm = NEWMOTOR(arm);
}

void ArmSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new ArmUpCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ArmSubsystem::Set(float speed)
{
    arm->Set(speed);
}

float ArmSubsystem::Get()
{
    return arm->Get();
}
