#ifndef CATAPULTLOCKCOMMAND_H
#define CATAPULTLOCKCOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultLockCommand: public CommandBase {
public:
	CatapultLockCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
