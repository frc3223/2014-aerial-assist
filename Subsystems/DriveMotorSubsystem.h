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
    RobotDrive *moveDrive;
public:
    DriveMotorSubsystem();
    void InitDefaultCommand();
    void Drive(float magnitude = 0,float curve = 0);
    void ArcadeDrive(float moveValue,float direction,bool squaredInputs = true);
    void TankDrive(float leftValue,float rightValue,bool squaredInputs = true);
    void LeftSet(float speed=0);
    void RightSet(float speed=0);
};

#endif
