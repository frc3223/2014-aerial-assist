#ifndef ARMSUBSYSTEM_H
#define ARMSUBSYSTEM_H
#include "WPILib.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class ArmSubsystem: public Subsystem
{
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    SpeedController *arm;
public:
    ArmSubsystem();
    void InitDefaultCommand();
    void Set(float speed = 0);
    float Get();
};

#endif
