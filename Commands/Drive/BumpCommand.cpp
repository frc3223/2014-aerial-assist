#include "BumpCommand.h"
#include <math.h>

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
    float moveX = SENSOR_GET(joystick,main,RightJoyX);
    if (abs(moveY)>0.5) {moveY = copysign(speed,moveY); moveX = 0;}
    else if (abs(moveX)>0.5) {moveX = copysign(speed,moveY); moveY = 0;};
    drivemotorsubsystem->ArcadeDrive(moveX,-moveY);
}

// Make this return true when this Command no longer needs to run execute()
bool BumpDriveCommand::IsFinished()
{
    return SENSOR_GET(joystickbutton,);
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
