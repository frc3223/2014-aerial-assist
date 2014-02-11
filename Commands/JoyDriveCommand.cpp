#include "JoyDriveCommand.h"

/**
 * Runs the drive subsystem with the joysticks.
 */

JoyDriveCommand::JoyDriveCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(drivemotorsubsystem);
}

// Called just before this Command runs the first time
void JoyDriveCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
/// Runs the joystick on tank drive, with the slow button halving the inputs.
void JoyDriveCommand::Execute()
{
    oi->buttonSlow->Get() ? drivemotorsubsystem->ArcadeDrive(LEFTJOYY/2,-LEFTJOYX
            /2) : drivemotorsubsystem->ArcadeDrive(LEFTJOYY,-LEFTJOYX);
}

// Make this return true when this Command no longer needs to run execute()
bool JoyDriveCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void JoyDriveCommand::End()
{
    drivemotorsubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoyDriveCommand::Interrupted()
{
    drivemotorsubsystem->Stop();
}
