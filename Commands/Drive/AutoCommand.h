#ifndef AUTODRIVECOMMAND_H
#define AUTODRIVECOMMAND_H

#include <functional>
#include "../../CommandBase.h"
#include "../../Robotmagic.h"
#include "../../Lib/AutoDrive.h"

/**
 *
 *
 * @author frc
 */
class AutoDriveCommand: public CommandBase
{
private:
    bool finished;
public:
    AutoDriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
