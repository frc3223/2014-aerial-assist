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
    Relay *forward1Relay;
    Relay *reverse1Relay;
    Relay *forward2Relay;
    Relay *reverse2Relay;
public:
    CatapultSubsystem();
    void InitDefaultCommand();
    Relay::Value Get(Relay::Value value,int number);
    void Set(Relay::Value value,int number = 1);
};

#endif
