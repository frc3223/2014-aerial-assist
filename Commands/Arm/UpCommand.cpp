#include "UpCommand.h"

ArmUpCommand::ArmUpCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(armsubsystem);
}

// Called just before this Command runs the first time
void ArmUpCommand::Initialize()
{
    if (!SENSOR_GET(digitalin,arm_top)) armsubsystem->Set(-.4);
}

// Called repeatedly when this Command is scheduled to run
void ArmUpCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUpCommand::IsFinished()
{
    return SENSOR_GET(digitalin,arm_top);
}

// Called once after isFinished returns true
void ArmUpCommand::End()
{
    armsubsystem->Set();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUpCommand::Interrupted()
{
    armsubsystem->Set();
}
