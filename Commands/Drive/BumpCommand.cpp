#include "BumpCommand.h"

/**
 * Runs the drive subsystem with the joysticks.
 */

BumpDriveCommand::BumpDriveCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(drivemotorsubsystem);
}

// Called just before this Command runs the first time
void BumpDriveCommand::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
/// Runs the joystick on tank drive, with the slow button halving the inputs.
void BumpDriveCommand::Execute()
{
    float speed = SENSOR_GET(joystickbutton,Slow) ? 0.5 : 1;
    float moveY = SENSOR_GET(joystick,main,RightJoyY);
    float moveYSign = (moveY > 0) - (moveY < 0);
    float moveX = SENSOR_GET(joystick,main,RightJoyX);
    float moveXSign = (moveX > 0) - (moveX < 0);
    if (abs(moveY)>0.5) {moveY = speed*moveYSign; moveX = 0;}
    else if (abs(moveX)>0.5) {moveX = speed*moveXSign; moveY = 0;};
    drivemotorsubsystem->ArcadeDrive(moveX,-moveY);
}

// Make this return true when this Command no longer needs to run execute()
bool BumpDriveCommand::IsFinished()
{
    return SENSOR_GET(joystickbutton,Square);
}

// Called once after isFinished returns true
void BumpDriveCommand::End()
{
    drivemotorsubsystem->Drive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BumpDriveCommand::Interrupted()
{
    drivemotorsubsystem->Drive();
}
