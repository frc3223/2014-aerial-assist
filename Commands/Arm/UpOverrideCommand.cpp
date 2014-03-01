#include "UpOverrideCommand.h"

ArmUpOverrideCommand::ArmUpOverrideCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(armsubsystem);
}

// Called just before this Command runs the first time
void ArmUpOverrideCommand::Initialize()
{
    armsubsystem->Set(-.2);
}

// Called repeatedly when this Command is scheduled to run
void ArmUpOverrideCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ArmUpOverrideCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void ArmUpOverrideCommand::End()
{
    armsubsystem->Set();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmUpOverrideCommand::Interrupted()
{
    armsubsystem->Set();
}
