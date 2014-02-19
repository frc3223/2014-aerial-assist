#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Subsystems/DriveMotorSubsystem.h"
#include "Subsystems/CompressorSubsystem.h"
#include "Subsystems/ArmSubsystem.h"
#include "OI.h"
#include "Robotmagic.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
    CommandBase(const char *name);
    CommandBase();
    static void init();
    // Create a single static instance of all of your subsystems
    static DriveMotorSubsystem *drivemotorsubsystem;
    static CompressorSubsystem *compressorsubsystem;
    static ArmSubsystem *armsubsystem;
    static OI *OI_VAR;
};

#endif
