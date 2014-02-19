#ifndef CATAPULTFIRECOMMAND_H
#define CATAPULTFIRECOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultFireCommand: public CommandBase {
public:
	CatapultFireCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
