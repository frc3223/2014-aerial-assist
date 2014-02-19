#ifndef CATAPULTRETRACTCOMMAND_H
#define CATAPULTRETRACTCOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultRetractCommand: public CommandBase {
public:
	CatapultRetractCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
