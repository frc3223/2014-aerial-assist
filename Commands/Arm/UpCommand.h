#ifndef ARMUPCOMMAND_H
#define ARMUPCOMMAND_H

#include "../CommandBase.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class ArmUpCommand: public CommandBase
{
public:
    ArmUpCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
