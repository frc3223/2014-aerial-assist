#include "SetCommand.h"

CatapultSetCommand::CatapultSetCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(catapultsubsystem);
}

// Called just before this Command runs the first time
void CatapultSetCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CatapultSetCommand::Execute()
{
    catapultsubsystem->Set(CatapultSubsystem::little,Relay::kForward);
    SENSOR_GET(digitalin,catapult) ? catapultsubsystem->Set(CatapultSubsystem::big,Relay::kForward)
            : catapultsubsystem->Set(CatapultSubsystem::big,Relay::kReverse);
}

// Make this return true when this Command no longer needs to run execute()
bool CatapultSetCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void CatapultSetCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatapultSetCommand::Interrupted()
{
}
