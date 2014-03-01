#ifndef JOYDRIVECOMMAND_H
#define JOYDRIVECOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class JoyDriveCommand: public CommandBase
{
public:
    JoyDriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
