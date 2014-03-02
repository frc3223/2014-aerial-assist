#include "SetCommand.h"

constexpr auto switchtime = 500;

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
    printf("catapult set execute\n");
    catapultsubsystem->Set(CatapultSubsystem::little,Relay::kForward);
    if (SENSOR_GET(digitalin,catapult))
    {
        catapultsubsystem->Set(CatapultSubsystem::big,Relay::kForward);
        catapultsubsystem->Set(CatapultSubsystem::little,Relay::kForward);
    } else
    {
        catapultsubsystem->Set(CatapultSubsystem::big,Relay::kReverse);
        if ((GetFPGATime()%(switchtime*2))>=(switchtime))
            {catapultsubsystem->Set(CatapultSubsystem::little,Relay::kReverse);}
        else
            {catapultsubsystem->Set(CatapultSubsystem::little,Relay::kForward);}
    }
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
