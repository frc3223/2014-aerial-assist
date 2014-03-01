#ifndef DRIVEMOTORSUBSYSTEM_H
#define DRIVEMOTORSUBSYSTEM_H
#include "WPILib.h"
#include "../Robotmagic.h"
#include "../Lib/DualSpeedController.h"

/**
 *
 *
 * @author frc
 */
class DriveMotorSubsystem: public Subsystem
{
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    SpeedController *leftController;
    SpeedController *rightController;
    RobotDrive *moveDrive;
public:
    DriveMotorSubsystem();
    void InitDefaultCommand();
    void Drive(float magnitude = 0,float curve = 0);
    void ArcadeDrive(float moveValue,float direction,bool squaredInputs = true);
    void TankDrive(float leftValue,float rightValue,bool squaredInputs = true);
    void MoveRotate(std::function<float ()> distGet,
        std::function<float ()> angleGet,
        std::function<float ()> speedGet,
        float distance,float angle);
};

#endif
