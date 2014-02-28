#include "AutoDriveCommand.h"

/**
 * Runs the drive subsystem with the joysticks.
 */

AutoDriveCommand::AutoDriveCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(drivemotorsubsystem);
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
}

// Takes as input sensor vars drive_dist (in whatever units your encoder uses), drive_angle (in degrees), and drive_speed (in (0,1]).
void AutoDriveCommand::Execute()
{
    double dist = SENSOR_GET(var,drive_dist,double);
    double angle = SENSOR_GET(var,drive_angle,double);
    double speed = SENSOR_GET(var,drive_speed,double);
    SENSOR_GET(joystickbutton,Slow) ? drivemotorsubsystem->Drive
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommand::IsFinished()
{
    return false;
}

// Called once after isFinished returns true
void AutoDriveCommand::End()
{
    drivemotorsubsystem->Drive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCommand::Interrupted()
{
    drivemotorsubsystem->Drive();
}
