#include "CommandBase.h"
// A macro to make the code cleaner
#define SUBINIT(full,name) full* CommandBase::name = NULL

CommandBase::CommandBase(const char *name) :
    Command(name)
{
}

CommandBase::CommandBase() :
    Command()
{
}
// Initialize a single static instance of all of your subsystems to NULL
SUBINIT(DriveMotorSubsystem,drivemotorsubsystem);
SUBINIT(CompressorSubsystem,compressorsubsystem);
SUBINIT(CatapultSubsystem,catapultsubsystem);
SUBINIT(ArmSubsystem,armsubsystem);
SUBINIT(OI,OI_VAR);

void CommandBase::init()
{
    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    drivemotorsubsystem = new DriveMotorSubsystem();
    compressorsubsystem = new CompressorSubsystem();
    catapultsubsystem = new CatapultSubsystem();
    armsubsystem = new ArmSubsystem();

    OI_VAR = new OI();
}
