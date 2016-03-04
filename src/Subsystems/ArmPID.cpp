// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ArmPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"

namespace
{
	const double c_sensorVoltRange = 4.0; //0.5 - 4.5
	const double c_sensorAngleRange = 360.0;

#ifdef PracticeBot
	const double c_ArmAngleDifference = 18;// positive if angle is above horizontal -- started at 37, 46.5
#endif

#ifdef CompBot
	const double c_ArmAngleDifference = 18.5;// positive if angle is above horizontal
#endif
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ArmPID::ArmPID() : PIDSubsystem("ArmPID", 1.0, 0.0, 0.0) {
    SetAbsoluteTolerance(0.2);
    GetPIDController().get()->SetContinuous(false);
    LiveWindow::GetInstance()->AddActuator("ArmPID", "PIDSubsystem Controller", GetPIDController());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    armMotorRight = RobotMap::armPIDArmMotorRight;
    armMotorLeft = RobotMap::armPIDArmMotorLeft;
    lowBarProx1 = RobotMap::armPIDLowBarProx1;
    lowBarProx2 = RobotMap::armPIDLowBarProx2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    armAngle = RobotMap::armPIDArmAngle;

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
     Disable(); // - Enables the PID controller.
     m_commandIsActive = false;
}

double ArmPID::ReturnPIDInput() {

	return GetArmAngle();

    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
    //    return armAngle->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ArmPID::SetArmAngle(float angle){
//	double m_Angle = angle;
//	double m_goingUp = false;
//
//		m_goingUp = (Robot::armPID.get()->GetArmAngle() > m_Angle ? true : false);
//
//		Robot::armPID.get()->SetCommandActive(true);
//
//		float currentAngle = Robot::armPID.get()->GetArmAngle();
//			double output = 0;
//
//			if(currentAngle < m_Angle)
//			{
//				//go up
//				if(currentAngle < 20)
//				{
//					output = -0.3;
//				}
//				else
//				{
//					output = -1.0;
//				}
//			}
//			else if (currentAngle > m_Angle){
//				if (currentAngle < 20)
//				{
//					output = 0.3;
//				}
//				else
//				{
//					output = 1.0;
//				}
//			}
//
//	std::cout<< "  Angle" << currentAngle;
//
//			Robot::armPID.get()->UsePIDOutput(output);
//
//	GetPIDController().get()->Disable();
//	GetPIDController().get()->SetSetpoint(convertAngleToVolts(angle));
//	GetPIDController().get()->Enable();
}


float ArmPID::GetArmAngle(){
	float angle = convertVoltsToAngle(armAngle.get()->GetVoltage());
	//std::cout << " Get Arm Angle : " << angle;
	//std::cout << " Return Arm Angle : " <<  180 - angle - c_ArmAngleDifference;
	return 180 - angle - c_ArmAngleDifference;
}

double ArmPID::convertAngleToVolts(double angle)
{
	return (((c_sensorVoltRange/c_sensorAngleRange)*(angle))+.5);
}

double ArmPID::convertVoltsToAngle(double volts)
{
	return (((c_sensorAngleRange/c_sensorVoltRange)*(volts-.5)));
}

void ArmPID::UsePIDOutput(double output) {
	if(!AngleCheck(output))
	{
		output = 0;
	}
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT
    armMotorRight->PIDWrite(output);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=OUTPUT

    armMotorLeft->PIDWrite(-output);
}

void ArmPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ArmPID::ManualArmControl(double output) //will not set output if command is running
{
	if(!m_commandIsActive)
	{
		double allowed = output;
		if(fabs(output) < .15)
		{
			allowed = 0;
		}
		if(!AngleCheck(allowed))
		{
			allowed = 0;
		}
		UsePIDOutput(allowed);
	}
}

bool ArmPID::AngleCheck(double output)
{
	if(((GetArmAngle() > 90) && (output < 0)) ||
		((GetArmAngle() < -1) && (output > 0)))
	{
		return false;
	}
	return true;
}

void ArmPID::SetCommandActive(bool active)
{
	m_commandIsActive = active;
}


