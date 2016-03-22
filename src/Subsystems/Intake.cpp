// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Intake.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Intake::Intake() : Subsystem("Intake") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	mainIntake = RobotMap::intakeMainIntake;
	secondIntake = RobotMap::intakeSecondIntake;
	m_IntakeOn = false;
	ballRelease = RobotMap::intakeBallRelease;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ballDetector = RobotMap::intakeBallDetector;
	m_SecondaryOn = false;
}

void Intake::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Intake::ToggleIntake() {
	if(m_IntakeOn){
		SetIntakeOff();//intake is on we need to turn it off
	}
	else {
		SetIntakeOn();
	}
}

void Intake::SetIntakeOn() {
	mainIntake.get()->Set(1);
}

void Intake::SetIntakeOff() {
	mainIntake.get()->Set(0);
}

void Intake::SetIntakeOut(){
	mainIntake.get()->Set(-1);
}

void Intake::SetSecondaryOff() {
	secondIntake.get()->Set(0);
}

void Intake::SetSecondaryOn() {
	secondIntake.get()->Set(-1);
}

void Intake::SetSecondaryOut(){
	secondIntake.get()->Set(1);
}

void Intake::ToggleSecondary() {
	if(m_SecondaryOn) {
		SetSecondaryOff();
	}
	else {
		SetSecondaryOn();
	}
}
void Intake::SetBallRelease(ReleaseState state) {
	if(state == Released){
		ballRelease.get()->Set(true);
	}
	else if(state == Blocked) {
		ballRelease.get()->Set(false);
	}
}

bool Intake::IsBallDetected()
{
	return !(ballDetector.get()->Get());
}
