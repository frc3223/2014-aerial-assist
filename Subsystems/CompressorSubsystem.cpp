#include "CompressorSubsystem.h"
#include "../CommandBase.h"

CompressorSubsystem::CompressorSubsystem() :
    Subsystem("CompressorSubsystem")
{
    relay = new Relay(COMPRESSOR_RELAY_MODULE,COMPRESSOR_RELAY_CHANNEL);
}

void CompressorSubsystem::InitDefaultCommand()
{
    // Set the default command for a subsystem here.
    //SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

bool CompressorSubsystem::Enabled()
{
    return relay->Get();
}

void CompressorSubsystem::Start()
{
    relay->Set(Relay::kOn);
}

void CompressorSubsystem::Stop()
{
    relay->Set(Relay::kOff);
}
