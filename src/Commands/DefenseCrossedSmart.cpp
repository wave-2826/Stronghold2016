// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DefenseCrossedSmart.h"
#include <iostream>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DefenseCrossedSmart::DefenseCrossedSmart(PitchStep startStep, bool resetPitchRoll, bool checkRoll): Command() {
    stepCounter = startStep;
    m_resetPitchRoll = resetPitchRoll;
    m_checkRoll = checkRoll;

        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DefenseCrossedSmart::Initialize() {
	std::cout << "Initialize Defense Crossed" <<std::endl;

//	if(m_resetPitchRoll)
//	{
//		std::cout << "Resetting Pitch & Roll" << std::endl;
//		Robot::drivePID.get()->ResetPitchAndRoll();
//	}

	Robot::drivePID.get()->SetDefenseCrossed(false);
}

// Called repeatedly when this Command is scheduled to run
void DefenseCrossedSmart::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DefenseCrossedSmart::IsFinished() {
	float CurrentPitch = Robot::drivePID.get()->GetPitch();
	float CurrentRoll = Robot::drivePID.get()->GetRoll();
	bool IsPitchFlat = false;

	switch(stepCounter){
		case PitchStepIncrease:
			if (CurrentPitch > 7.0){
				std::cout<<" ------------------- Pitch Step Increase Finished ---------------------" << std::endl;
				stepCounter = PitchStepDecrease;
			}
			break;
		case PitchStepDecrease:
			if (CurrentPitch < -3.0){
				stepCounter = PitchStepFlat;
				std::cout<<" ------------------- Pitch Step Decrease Finished ---------------------" << std::endl;
			}
			break;
		case PitchStepFlat:
			std::cout<<" ------------------- Pitch Step Flat ---------------------" << std::endl;
			//IsPitchFlat = (fabs (CurrentPitch) < 3.0);
			IsPitchFlat = ((-1 < CurrentPitch) && (CurrentPitch < 3.0));
			break;
		case PitchStepIncreaseBack:
			if (CurrentPitch > 4.5){
				std::cout<<" ------------------- Pitch Step Increase Back Finished ---------------------" << std::endl;
				stepCounter = PitchStepFlat;
			}
			break;
		case PitchStepIncreaseCDF: // i am 95% sure this is v BAD
			if(CurrentPitch < -5){
				std::cout << " ------------------- Pitch Step Increase CDF Finished --------------------- " << std::endl;
				return true;
			}
	}

	bool IsRollFlat = (m_checkRoll? (fabs (CurrentRoll) < 1.0) : true); //if we don't care about roll, assume roll is flat

	std::cout<< "Pitch: " << CurrentPitch <<" Roll: " << CurrentRoll << " IsPitchFlat: " << IsPitchFlat <<
			" IsRollFlat: " << IsRollFlat << std::endl;


	if (IsPitchFlat && IsRollFlat)
	{
		std::cout<<"Defense Crossed!!"<<std::endl;
		Robot::drivePID.get()->SetDefenseCrossed(true);
		return true;
	}

	else
	{
		return false;
	}

}

// Called once after isFinished returns true
void DefenseCrossedSmart::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DefenseCrossedSmart::Interrupted() {

}
