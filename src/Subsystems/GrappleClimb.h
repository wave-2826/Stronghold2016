// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef GRAPPLECLIMB_H
#define GRAPPLECLIMB_H
#include "Commands/Subsystem.h"
#include "WPILib.h"


enum ClimbState // NOT PNUMATIC
{
	Climb_Hold,
	Climb_Deploy,
	Climb_Release
};

enum GrappleState
{
	Grapple_Hold,
	Grapple_Release
};

/**
 *
 *
 * @author ExampleAuthor
 */
class GrappleClimb: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//std::shared_ptr<Solenoid> climbRelease;
	std::shared_ptr<Solenoid> grappleRelease;

	std::shared_ptr<CANTalon> climbMotor1;
	std::shared_ptr<CANTalon> climbMotor2;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	GrappleClimb();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	void SetClimbState(ClimbState state);

	void SetGrappleState(GrappleState state);
};

#endif
