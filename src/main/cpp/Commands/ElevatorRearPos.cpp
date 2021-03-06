// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/ElevatorRearPos.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

/**
 * @brief Construct a new Elevator Rear Pos:: Elevator Rear Pos object
 * 
 * Set the m_position and m_instant variables (in command scope)
 * from constructor parameters.
 * 
 * @param position 
 * @param instant 
 */
ElevatorRearPos::ElevatorRearPos(double position, bool instant): frc::Command() {
    m_position = position;
    m_instant = instant;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::elevator.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

/**
 * @brief Called just before this Command runs the first time
 */
void ElevatorRearPos::Initialize() {
    SetTimeout(5.0);
}

/**
 * @brief Called repeatedly when this Command is scheduled to run
 * 
 * Constantly sets the rear elevator position to m_position.
 */
void ElevatorRearPos::Execute() {
    Robot::elevator->SetRearPosition(m_position);
}

/**
 * @brief Make this return true when this Command no longer needs to run execute()
 * 
 * Depending on M_instant flag, this command may be completed instanteously
 * or may take a while (and be completely only when the desired positon is reached).
 * 
 * @return true 
 * @return false 
 */
bool ElevatorRearPos::IsFinished() {
    bool retVal = false;
    if (m_instant) {
        retVal = true;
    }
    else if (Robot::elevator->RearAtPosition())
    {
        retVal = true;
    }
    else if (IsTimedOut()) {
        retVal = true;
    }
    return retVal;
}

/**
 * @brief Called once after isFinished returns true
 */
void ElevatorRearPos::End() {

}

/**
 * @brief Called when another command which requires one or more of the same subsystems is scheduled to run
 */
void ElevatorRearPos::Interrupted() {

}
