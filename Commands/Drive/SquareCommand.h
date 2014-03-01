#ifndef SQUAREDRIVECOMMAND_H
#define SQUAREDRIVECOMMAND_H

#include <functional>
#include "../../CommandBase.h"
#include "../../Robotmagic.h"
#include "../../Lib/AutoDrive.h"

/**
 *
 *
 * @author frc
 */
class SquareDriveCommand: public CommandBase
{
private:
    bool finished;
public:
    SquareDriveCommand();
    virtual void Initialize();
    virtual void Execute();
    virtual bool IsFinished();
    virtual void End();
    virtual void Interrupted();
};

#endif
