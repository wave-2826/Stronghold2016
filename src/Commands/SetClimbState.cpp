// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "SetClimbState.h"
#include "../Subsystems/grappleClimb.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SetClimbState::SetClimbState(): Command() {
	Requires(Robot::grappleClimb.get());
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	m_position = Climb_Close;

}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

SetClimbState::SetClimbState(ClimbState position): Command() {
	Requires(Robot::grappleClimb.get());
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES

	m_position = position;
}



// Called just before this Command runs the first time
void SetClimbState::Initialize() {
	Robot::grappleClimb.get()->setClimbState(m_position);
}

// Called repeatedly when this Command is scheduled to run
void SetClimbState::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool SetClimbState::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void SetClimbState::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetClimbState::Interrupted() {

}
