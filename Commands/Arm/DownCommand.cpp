#include "DownCommand.h"

ArmDownCommand::ArmDownCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(armsubsystem);
}

// Called just before this Command runs the first time
void ArmDownCommand::Initialize()
{
    if (!SENSOR_GET(digitalin,arm_bot)) armsubsystem->Set(.2);
}

// Called repeatedly when this Command is scheduled to run
void ArmDownCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ArmDownCommand::IsFinished()
{
    return SENSOR_GET(digitalin,arm_bot);
}

// Called once after isFinished returns true
void ArmDownCommand::End()
{
    armsubsystem->Set();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDownCommand::Interrupted()
{
    armsubsystem->Set();
}
