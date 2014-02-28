#ifndef AUTODRIVECOMMAND_H
#define AUTODRIVECOMMAND_H

#include "../CommandBase.h"
#include "../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class AutoDriveCommand: public CommandBase
{
public:
    AutoDriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
