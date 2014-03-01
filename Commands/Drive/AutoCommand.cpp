#include "AutoCommand.h"

AutoDriveCommand::AutoDriveCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(drivemotorsubsystem);
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
    bool finished = false;
}

void AutoDriveCommand::Execute()
{
    static float const bump_dist  = .2; // encoder units
    static float const bump_angle = 15; // degrees
    float speed = 1;
    char direction;
    if (SENSOR_GET(joystick,main,BumpJoy)>0.5) { direction = 'e'; }
    else if (SENSOR_GET(joystick,main,BumpJoy)<-0.5) { direction = 'w'; };
    float dist, angle;
    switch (direction)
    {
        case 'n':
            dist  = bump_dist;
            angle = 0;
            break;
        case 's':
            dist  = -bump_dist;
            angle = 0;
            break;
        case 'e':
            dist  = 0;
            angle = bump_angle;
            break;
        case 'w':
            dist  = 0;
            angle = -bump_angle;
            break;
    }
    float initGyro = SENSOR_GET(gyro,gyro);
    float initEncoder = SENSOR_GET(encoder,AUTODRIVE_ENCODER);
    drivemotorsubsystem->MoveRotate([&](){return SENSOR_GET(encoder,AUTODRIVE_ENCODER)-initEncoder;},
            [&](){return SENSOR_GET(gyro,gyro)-initGyro;},
            [&](){return speed*(SENSOR_GET(joystickbutton,Slow)?0.5:1);},
            dist,angle);
    finished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommand::IsFinished()
{
    return finished;
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
