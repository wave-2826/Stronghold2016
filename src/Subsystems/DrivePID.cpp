// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "DrivePID.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "../Robot.h"
#include "../WaveConstants.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID
DrivePID::DrivePID() : PIDSubsystem("DrivePID", .0175, 0, 0/*0.000001*/) {   //.04, 0.001, 0.0001
    SetAbsoluteTolerance(0.05);
    GetPIDController()->SetContinuous(true);
    LiveWindow::GetInstance()->AddActuator("DrivePID", "PIDSubsystem Controller", GetPIDController());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PID

    GetPIDController()->SetInputRange(-180, 180); //range on max we should ever be off
	GetPIDController()->SetOutputRange(-1.0, 1.0); //range on motors
	GetPIDController()->SetAbsoluteTolerance(0); //plus or minus this voltage

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    driveEncoderRight = RobotMap::drivePIDDriveEncoderRight;
    driveEncoderLeft = RobotMap::drivePIDDriveEncoderLeft;
    leftBack = RobotMap::drivePIDLeftBack;
    rightBack = RobotMap::drivePIDRightBack;
    leftFront = RobotMap::drivePIDLeftFront;
    rightFront = RobotMap::drivePIDRightFront;
    robotDrive41 = RobotMap::drivePIDRobotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    gyro = RobotMap::m_gyro;
    gyro.get()->ZeroYaw();

//    robotDrive41.get()->SetExpiration(1.00);
    robotDrive41.get()->SetSafetyEnabled(false);

    // Use these to get going:
    // SetSetpoint() -  Sets where the PID controller should move the system
    //                  to
    // Enable() - Enables the PID controller.
}


void DrivePID::SetDirection(double heading)
{
	GetPIDController()->Disable();
	GetPIDController()->Reset();
    gyro.get()->ZeroYaw();
	GetPIDController()->SetSetpoint(heading); //we are now facing the same way the entire time
}


double DrivePID::ReturnPIDInput() {

	return GetYaw();

	// Return your input value for the PID loop
    // e.g. a sensor, like a potentiometer:
    // yourPot->SetAverageVoltage() / kYourMaxVoltage;
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
        return driveEncoderRight->PIDGet();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=SOURCE
}

void DrivePID::UsePIDOutput(double output) {
	//std::cout << "DrivePID - UsePIDOutput = " << output << std::endl;

//	SetSidePower(output, -output); // so there is not discord between this directly calling PIDoutput value and SetSidePower
//	if(fabs(output) > .75)
//	{
//		if(output > 0)
//		{
//			output = .75;
//		}
//		else
//		{
//			output = -.75;
//		}
//	}
	robotDrive41.get()->TankDrive(-output, output);
//    leftBack->PIDWrite(output);
//    leftFront->PIDWrite(output);
//    rightBack->PIDWrite(-output);
//    rightFront->PIDWrite(-output);
}

void DrivePID::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void DrivePID::ResetEncoders() {

	driveEncoderRight.get()->Reset();
	driveEncoderLeft.get()->Reset();
}

double DrivePID::GetDistanceTraveled(){
	double rightDistance = driveEncoderRight.get()->GetDistance(); // Get() * wheelCircumference * ticksPerWheel;
	double leftDistance = driveEncoderLeft.get()->GetDistance(); //Get() * wheelCircumference * ticksPerWheel;
//	std::cout << " Left Drive = " << leftDistance << ", Right Drive = " << rightDistance << std::endl;
	return (rightDistance+leftDistance)/2;


//	double rightDistance = driveEncoderRight.get()->Get();// * (6.1 * 3.14159) / 128;
//	double leftDistance = driveEncoderLeft.get()->Get() * (6.1 * 3.14159) / 128;
//	return leftDistance;
}


void DrivePID::DriveStraight(double power) {

	//std::cout << "Drive: Moving straight with power: " << power << std::endl;
	double correction = Robot::drivePID->GetPIDOutput();
	SetSidePower(power - correction, power + correction);
	double degreesOff = GetSetpoint() - GetYaw();
	std::cout << "Correction: " << correction << "\tLeft: " <<
				(power - correction) << "\tRight: " << (power + correction) << "\tYaw: "
			<< GetYaw() << "\tSetpoint: " << GetSetpoint() <<  "\tOff By: " << degreesOff << std::endl;

}

void DrivePID::SetSidePower(double left,double right){
//	std::cout << "SetSidePower:  Left = " << left << ", Right = " << right << std::endl;
//	leftFront.get()->Set(-left);
//	leftBack.get()->Set(-left);
//	rightBack.get()->Set(right);
//	rightFront.get()->Set(right);
	robotDrive41.get()->TankDrive(left, right);

	if(0 == left && 0 == right)
	{
		GetPIDController()->Disable();
	}
}

double DrivePID::GetPIDOutput()
{
	return GetPIDController()->Get();
}

double DrivePID::GetYaw() {
	return gyro.get()->GetYaw();
}

double DrivePID::GetPitch() {
	return (gyro.get()->GetPitch() - m_resetPitch);
}

double DrivePID::GetRoll() {
	return (gyro.get()->GetRoll() - m_resetRoll);
}

void DrivePID::ResetPitchAndRoll() {
	std::cout << "Resetting Pitch & Roll" << std::endl;
	m_resetPitch =  gyro.get()->GetPitch();
	m_resetRoll =  gyro.get()->GetRoll();
}

void DrivePID::SetPIDs(double p, double i, double d){

}

void DrivePID::SetDefenseCrossed(bool isDefenseCrossed){
	defenseIsCrossed = isDefenseCrossed;
}

void DrivePID::SetDrive_Brake(bool brake)
{
	if(brake)
	{
		leftBack.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
		leftFront.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
		rightBack.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
		rightFront.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Brake);
	}
	else
	{
		leftBack.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		leftFront.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		rightBack.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
		rightFront.get()->ConfigNeutralMode(CANSpeedController::kNeutralMode_Coast);
	}
}
