#ifndef CATAPULTPRIMECOMMAND_H
#define CATAPULTPRIMECOMMAND_H

#include "../../CommandBase.h"
#include "../../Robotmagic.h"

/**
 *
 *
 * @author frc
 */
class CatapultPrimeCommand: public CommandBase {
public:
	CatapultPrimeCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
