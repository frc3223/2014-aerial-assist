#ifndef BUMPDRIVECOMMAND_H
#define BUMPDRIVECOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class BumpDriveCommand: public CommandBase
{
public:
    BumpDriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
