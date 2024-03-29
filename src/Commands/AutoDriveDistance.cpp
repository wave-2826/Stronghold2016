#include "AutoDriveDistance.h"
#include "../Robot.h"
#include "../AutonomousConstants.h"
#include <iostream>

AutoDriveDistance::AutoDriveDistance(double maxDistance, double power, float heading, bool useGlobalDistance){
	Requires(Robot::drivePID.get());
	std::cout << "AutoDriveDistance construct - start" << std::endl;
	m_distance = maxDistance;
	m_power = power;
	m_heading = heading;
	m_distanceTraveled = 0;
	m_useGlobalDistance = useGlobalDistance;
	std::cout << "   AutoDriveDistance construct - end" << std::endl;

}

void AutoDriveDistance::Initialize()
{
	if(m_useGlobalDistance)
	{
		AutonomousConstants autoConst;
		m_distance = autoConst.GetDistanceToTravel() * m_distance;
	}

	Robot::drivePID->ResetEncoders();
	//Robot::drivePID->SetPIDs(.055, 0, .08); // .035 //comp = .055 //
	//Robot::drivePID->SetDirection(m_heading); //sets up the PID for moving straight THIS IS WHAT MADE IT SPIN IN  CIRCLES!!!!!
}

void AutoDriveDistance::Execute()
{
	//double m_maxPower = Robot::drivePID->CheckPower(m_power, m_distance); // get the max power allowed to move (basically P)
	Robot::drivePID->DriveStraight(m_power); //sets the correction based on degrees off the angle
}

bool AutoDriveDistance::IsFinished()
{
	m_distanceTraveled = Robot::drivePID->GetDistanceTraveled();
	std::cout << "Distance to Go: " << m_distance << "\tTraveled: " << Robot::drivePID->GetDistanceTraveled() << "\tPower: " << m_power << std::endl;

	if(m_power > 0 && m_distanceTraveled > m_distance){  //driving forwards
		return true;
	}
	else if(m_power < 0 && m_distanceTraveled < m_distance){  //driving backwards
		return true;
	}

	else if(m_power == 0){
		return true;
	}
	else{
		return false; // return false, allowing us to destroy this command when a new instance starts
	}
}

void AutoDriveDistance::End()
{
	Robot::drivePID->SetSidePower(0,0); // stop moving
}

void AutoDriveDistance::Interrupted()
{
	End();
}
