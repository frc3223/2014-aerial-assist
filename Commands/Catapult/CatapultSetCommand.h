#ifndef CATAPULTSETCOMMAND_H
#define CATAPULTSETCOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultSetCommand: public CommandBase {
public:
	CatapultSetCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
