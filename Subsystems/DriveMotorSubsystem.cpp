#include "DriveMotorSubsystem.h"
#include "../Robotmap.h"
#include "../Commands/JoyDriveCommand.h"
#include "../DualSpeedController.h"

DriveMotorSubsystem::DriveMotorSubsystem() : Subsystem("DriveMotorSubsystem") {
    leftDrive = new DualSpeedController(new Jaguar(LEFTMOVE1), new Jaguar(LEFTMOVE2)); // Sets up the left side
    rightDrive = new DualSpeedController(new Jaguar(RIGHTMOVE1), new Jaguar(RIGHTMOVE2)); // Sets up the right side
    moveDrive = new RobotDrive(leftDrive,rightDrive); // Sets up the drive system
}

void DriveMotorSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
    SetDefaultCommand(new JoyDriveCommand());
}

/// Pass-through to the RobotDrive::Drive function.
void DriveMotorSubsystem::Drive(float magnitude, float curve) {
    moveDrive->Drive(magnitude, curve);
}

/// Pass-through to the RobotDrive::ArcadeDrive function.
void DriveMotorSubsystem::ArcadeDrive(float moveValue, float rotateValue, bool squaredInputs) //<
{
    moveDrive->ArcadeDrive(moveValue, rotateValue, squaredInputs);
}

/// Pass-through to the RobotDrive::TankDrive function.
void DriveMotorSubsystem::TankDrive(float leftValue, float rightValue, bool squaredInputs)
{
    moveDrive->TankDrive(leftValue, rightValue, squaredInputs);
}

/// Stops the motors.
void DriveMotorSubsystem::Stop() {
    moveDrive->Drive(0,0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
