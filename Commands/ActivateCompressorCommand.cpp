#include "ActivateCompressorCommand.h"

ActivateCompressorCommand::ActivateCompressorCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(compressorsubsystem);
}

// Called just before this Command runs the first time
void ActivateCompressorCommand::Initialize()
{
    if (SENSOR_GET(digitalin,compressor)) compressorsubsystem->Start();
}

// Called repeatedly when this Command is scheduled to run
void ActivateCompressorCommand::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ActivateCompressorCommand::IsFinished()
{
    return !(SENSOR_GET(digitalin,compressor));
}

// Called once after isFinished returns true
void ActivateCompressorCommand::End()
{
    compressorsubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ActivateCompressorCommand::Interrupted()
{
    compressorsubsystem->Stop();
}
