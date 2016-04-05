

// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "ShooterWheelPID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
ShooterWheelPID::ShooterWheelPID() : PIDSubsystem("ShooterWheelPID", .001, 0.0, 0.0) {
    SetAbsoluteTolerance(.2);
    GetPIDController()->SetContinuous(true);
    LiveWindow::GetInstance()->AddActuator("ShooterWheelPID", "PIDSubsystem Controller", GetPIDController());
    GetPIDController()->SetOutputRange(-1.0, 1.0);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    shooter1 = RobotMap::shooterWheelPIDShooter1;
    noUseEncoder = RobotMap::shooterWheelPIDNoUseEncoder;
    speedCounter = RobotMap::shooterWheelPIDSpeedCounter;
    shooter2 = RobotMap::shooterWheelPIDShooter2;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

//    speedCounter.get()->SetMaxPeriod(28262826);
//    speedCounter.get()->SetUpdateWhenEmpty(true); //??? what does this do
//    speedCounter.get()->Reset();

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
    StopWheel();
    m_buttonWheelSpeed = 0;
}

double ShooterWheelPID::ReturnPIDInput() {

	float value = speedCounter.get()->GetPeriod();
	return 60/value;

    // Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
     //   return shooter1->Get();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void ShooterWheelPID::UsePIDOutput(double output) {
    // Use output to drive your system, like a motor
    // e.g. yourMotor->Set(output);
//	std::cout << " Shooter Wheel Output " << output;
	if (output< 0){
		output = 0;
	}

	//std::cout << "\tShooter Output = " << output;

	shooter1.get()->Set(-output);
	shooter2.get()->Set(output);

}

void ShooterWheelPID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void ShooterWheelPID::StartWheel(){
	Enable();
}

void ShooterWheelPID::StopWheel(){
	Disable();
}

void ShooterWheelPID::SetSequenceSpeed(WheelSpeed newSpeed){
	switch(newSpeed){

			case Short_Shot:
			default:
				SetSpeed(7500); //PID takes down value several hundred
				break;
			case Add_Speed:
				AddSpeed();
				break;
			case OVER_NINE_K:
				SetSpeed(10000);
			case Subtract_Speed:
				SubtractSpeed();
				break;
			case Long_Shot_Angle:
				SetSpeed(10750); //9500 for good ball maybe
				break;
			case Long_Shot_Straight: //right bumper
				SetSpeed(7750); //6180 for GOOD BALLS, 6750 for BAD OR 7250 maybe
				break;
			case Bad_Ball_Shot:
				SetSpeed(8000);
				break;
			case Idle_Shot:
				SetSpeed(2000);
				break;
			case Kill_Shot:
				SetSpeed(0);
				break;
	}
	m_wheelSpeed = newSpeed;
}

WheelSpeed ShooterWheelPID::GetWheelSpeed(){
	return m_wheelSpeed;
}

void ShooterWheelPID::SetSpeed(double speed){
	StopWheel();
	GetPIDController()->SetSetpoint(speed);
	StartWheel();
}

void ShooterWheelPID::AddSpeed(){
	SetSpeed(GetSpeed() + 250);
}

void ShooterWheelPID::SubtractSpeed(){
	SetSpeed(GetSpeed() - 250);
}

double ShooterWheelPID::GetSpeed(){
	return GetPIDController()->GetSetpoint();
}

void ShooterWheelPID::IncreaseWheelOutput_5()
{
	StopWheel();
	m_buttonWheelSpeed += 0.05;
	if(m_buttonWheelSpeed > 1.0)
	{
		m_buttonWheelSpeed = 1.0;
	}
	shooter1.get()->Set(-m_buttonWheelSpeed);//right?? needed to be flipped
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::DecreaseWheelOutput_5()
{
	StopWheel();
	m_buttonWheelSpeed -= 0.05;
	if(m_buttonWheelSpeed < -1.0)
	{
		m_buttonWheelSpeed = -1.0;
	}
	shooter1.get()->Set(-m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::IncreaseWheelOutput_1()
{
	StopWheel();
	m_buttonWheelSpeed += 0.01;
	if(m_buttonWheelSpeed > 1.0)
	{
		m_buttonWheelSpeed = 1.0;
	}
	shooter1.get()->Set(-m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::DecreaseWheelOutput_1()
{
	StopWheel();
	m_buttonWheelSpeed += 0.05;
	if(m_buttonWheelSpeed < -1.0)
	{
		m_buttonWheelSpeed = -1.0;
	}
	shooter1.get()->Set(-m_buttonWheelSpeed);
	shooter2.get()->Set(m_buttonWheelSpeed);
}

void ShooterWheelPID::KillWheels(){
	shooter1.get()->Set(0);
	shooter2.get()->Set(0);
}
