#ifndef CATAPULTSUBSYSTEM_H
#define CATAPULTSUBSYSTEM_H
#include "../Robotmap.h"
#include "WPILib.h"

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
    Relay *forwardRelay;
    Relay *reverseRelay;
public:
    CatapultSubsystem();
    void InitDefaultCommand();
    Relay::Value Get(Relay::Value value);
    void Set(Relay::Value value);
};

#endif
