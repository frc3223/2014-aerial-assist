#include "CatapultLockCommand.h"

CatapultLockCommand::CatapultLockCommand() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void CatapultLockCommand::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void CatapultLockCommand::Execute() {
	
}

// Make this return true when this Command no longer needs to run execute()
bool CatapultLockCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void CatapultLockCommand::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CatapultLockCommand::Interrupted() {
}
