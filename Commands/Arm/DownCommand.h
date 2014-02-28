#ifndef ARMDOWNCOMMAND_H
#define ARMDOWNCOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class ArmDownCommand: public CommandBase
{
public:
    ArmDownCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
