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
    bool CompressorSubsystem::Enabled();
    bool CompressorSubsystem::GetPressureSwitchValue();
    void CompressorSubsystem::Start();
    void CompressorSubsystem::Stop();
};

#endif
