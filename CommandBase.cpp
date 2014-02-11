#include "CommandBase.h"
#include "Subsystems/DriveMotorSubsystem.h"
// A macro to make the code cleaner
#define SUBINIT(full,name) full* CommandBase::name = NULL

CommandBase::CommandBase(const char *name) : Command(name)
{
}

CommandBase::CommandBase() : Command()
{
}
// Initialize a single static instance of all of your subsystems to NULL
SUBINIT(DriveMotorSubsystem,drivemotorsubsystem);
SUBINIT(OI,oi);

void CommandBase::init()
{
    // Create a single static instance of all of your subsystems. The following
    // line should be repeated for each subsystem in the project.
    drivemotorsubsystem = new DriveMotorSubsystem();

    oi = new OI();
}
