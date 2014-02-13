#include "DriveMotorSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/JoyDriveCommand.h"
#include "../Lib/DualSpeedController.h"

DriveMotorSubsystem::DriveMotorSubsystem() :
    Subsystem("DriveMotorSubsystem")
{
    leftDrive1 = LEFTDRIVE1_NEW;
    leftDrive2 = LEFTDRIVE2_NEW;
    leftDrive = new DualSpeedController(leftDrive1,leftDrive2); // Sets up the left side
    rightDrive1 = RIGHTDRIVE1_NEW;
    rightDrive2 = RIGHTDRIVE2_NEW;
    rightDrive = new DualSpeedController(rightDrive1,rightDrive2); // Sets up the right side
    moveDrive = new RobotDrive(leftDrive,rightDrive); // Sets up the drive system
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

/// Stops the motors.
void DriveMotorSubsystem::Stop()
{
    moveDrive->Drive(0,0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
