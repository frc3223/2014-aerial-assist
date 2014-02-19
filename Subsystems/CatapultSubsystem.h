#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H
#include "WPILib.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultSubsystem: public Subsystem
{
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    Solenoid *forward1Solenoid;
    Solenoid *reverse1Solenoid;
    Solenoid *forward2Solenoid;
    Solenoid *reverse2Solenoid;
public:
    CatapultSubsystem();
    void InitDefaultCommand();
    enum CylinderType
    {
        big = 1, little = 0
    };
    void Set(CatapultSubsystem::CylinderType type,Relay::Value value);
};

#endif
