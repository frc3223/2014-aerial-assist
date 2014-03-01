#include "SquareCommand.h"

SquareDriveCommand::SquareDriveCommand()
{
    // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    Requires(drivemotorsubsystem);
}

// Called just before this Command runs the first time
void SquareDriveCommand::Initialize()
{
    bool finished = false;
}

void SquareDriveCommand::Execute()
{
    constexpr float speed = 1;
    float initGyro = SENSOR_GET(gyro,gyro);
    float angle = -(fmod(initGyro+360,720)-360);
    drivemotorsubsystem->MoveRotate([&](){return 0;},
            [&](){return SENSOR_GET(gyro,gyro)-initGyro;},
            [&](){return speed*(SENSOR_GET(joystickbutton,Slow)?0.5:1);},
            0,angle);
    finished = true;
}

// Make this return true when this Command no longer needs to run execute()
bool SquareDriveCommand::IsFinished()
{
    return finished;
}

// Called once after isFinished returns true
void SquareDriveCommand::End()
{
    drivemotorsubsystem->Drive();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SquareDriveCommand::Interrupted()
{
    drivemotorsubsystem->Drive();
}
