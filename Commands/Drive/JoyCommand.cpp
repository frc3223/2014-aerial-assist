#include "JoyCommand.h"

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
    SENSOR_GET(joystickbutton,Slow) ? drivemotorsubsystem->ArcadeDrive(SENSOR_GET(joystick,main,LeftJoyY)/2,-SENSOR_GET(joystick,main,LeftJoyX)/2)
            : drivemotorsubsystem->ArcadeDrive(SENSOR_GET(joystick,main,LeftJoyY),-SENSOR_GET(joystick,main,LeftJoyX));
}

// Make this return true when this Command no longer needs to run execute()
bool JoyDriveCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void JoyDriveCommand::End()
{
    drivemotorsubsystem->Drive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoyDriveCommand::Interrupted()
{
    drivemotorsubsystem->Drive();
}
