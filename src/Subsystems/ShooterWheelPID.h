// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef SHOOTERWHEELPID_H
#define SHOOTERWHEELPID_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */

enum WheelSpeed
{
	Long_Shot_Angle,
	Long_Shot_Straight,
	OVER_NINE_K,
	Add_Speed,
	Subtract_Speed,
	Short_Shot,
	Idle_Shot,
	Kill_Shot,
	Bad_Ball_Shot,
};

class ShooterWheelPID: public PIDSubsystem {

private:
	WheelSpeed m_wheelSpeed;
	void AddSpeed();
	void SubtractSpeed();

 public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<CANTalon> shooter1;
	std::shared_ptr<Encoder> noUseEncoder;
	std::shared_ptr<Counter> speedCounter;
	std::shared_ptr<CANTalon> shooter2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	ShooterWheelPID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
	void StartWheel();
	void StopWheel();
	void SetSequenceSpeed(WheelSpeed newSpeed);
	WheelSpeed GetWheelSpeed();
	void SetSpeed(double speed);
	double GetSpeed();

	void IncreaseWheelOutput_5();
	void DecreaseWheelOutput_5();
	void IncreaseWheelOutput_1();
	void DecreaseWheelOutput_1();
	void KillWheels();
	double m_buttonWheelSpeed;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
