#include "DriveMotorSubsystem.h"
#include "../Commands/Drive/JoyCommand.h"
#include "../Lib/AutoDrive.h"

DriveMotorSubsystem::DriveMotorSubsystem() :
    Subsystem("DriveMotorSubsystem")
{
    leftController  = new DualSpeedController(NEWMOTOR(left1),NEWMOTOR(left2));
    rightController = new DualSpeedController(NEWMOTOR(right1),NEWMOTOR(right2));
    moveDrive       = new RobotDrive(leftController,rightController); // Sets up the drive system
}

void DriveMotorSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new JoyDriveCommand());
}

/// Pass-through to the RobotDrive::Drive function.
void DriveMotorSubsystem::Drive(float magnitude,float curve)
{
    moveDrive->Drive(magnitude,curve);
}

/// Pass-through to the RobotDrive::ArcadeDrive function.
void DriveMotorSubsystem::ArcadeDrive(float moveValue,float rotateValue,bool squaredInputs)
{
    moveDrive->ArcadeDrive(moveValue,rotateValue,squaredInputs);
}

/// Pass-through to the RobotDrive::TankDrive function.
void DriveMotorSubsystem::TankDrive(float leftValue,float rightValue,bool squaredInputs)
{
    moveDrive->TankDrive(leftValue,rightValue,squaredInputs);
}

/// Atomic move-rotate for easy autonomous control.
void DriveMotorSubsystem::MoveRotate(std::function<float ()> distGet,
        std::function<float ()> angleGet,
        std::function<float ()> speedGet,
        float distance,float angle)
{
    autoDrive([&](float dist){leftController->Set(dist);},
            [&](float dist){rightController->Set(dist);},
            distGet,
            angleGet,
            speedGet,
            distance,angle);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
