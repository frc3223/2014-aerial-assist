#ifndef ARMUPOVERRIDECOMMAND_H
#define ARMUPOVERRIDECOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class ArmUpOverrideCommand: public CommandBase
{
public:
    ArmUpOverrideCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
