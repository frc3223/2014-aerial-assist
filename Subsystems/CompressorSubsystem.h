#ifndef COMPRESSORSUBSYSTEM_H
#define COMPRESSORSUBSYSTEM_H
#include "WPILib.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CompressorSubsystem: public Subsystem
{
private:
    // It's desirable that everything possible under private except
    // for methods that implement subsystem capabilities
    Relay *relay;
public:
    CompressorSubsystem();
    void InitDefaultCommand();
    bool Enabled();
    bool GetPressureSwitchValue();
    void Start();
    void Stop();
};

#endif
