#ifndef ACTIVATECOMPRESSORCOMMAND_H
#define ACTIVATECOMPRESSORCOMMAND_H

#include "../CommandBase.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class ActivateCompressorCommand: public CommandBase
{
public:
    ActivateCompressorCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
