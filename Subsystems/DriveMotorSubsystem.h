#ifndef DRIVEMOTORSUBSYSTEM_H
#define DRIVEMOTORSUBSYSTEM_H
#include "WPILib.h"

/**
 *
 *
 * @author frc
 */
class DriveMotorSubsystem: public Subsystem {
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    SpeedController *leftDrive;
    SpeedController *rightDrive;
    RobotDrive *moveDrive;
public:
    DriveMotorSubsystem();
    void InitDefaultCommand();
    void Drive(float magnitude, float curve);
    void ArcadeDrive(float moveValue, float direction, bool squaredInputs=true);
    void TankDrive(float leftValue, float rightValue, bool squaredInputs=true);
    void Stop();
};

#endif
