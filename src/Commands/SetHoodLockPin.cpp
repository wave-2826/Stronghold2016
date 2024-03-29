// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SetHoodLockPin.h"
#include "../Subsystems/Hood.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SetHoodLockPin::SetHoodLockPin(): Command() {
	Requires(Robot::hood.get());
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_locked = false;

}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SetHoodLockPin::SetHoodLockPin(bool locked): Command() {
	Requires(Robot::hood.get());
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	m_locked = locked;
}



// Called just before this Command runs the first time
void SetHoodLockPin::Initialize() {
	if(m_locked) {
		Robot::hood.get()->setLockPin();
	}
	else{
		Robot::hood.get()->unlockPin();
	}
}
// Called repeatedly when this Command is scheduled to run
void SetHoodLockPin::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetHoodLockPin::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void SetHoodLockPin::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetHoodLockPin::Interrupted() {

}
