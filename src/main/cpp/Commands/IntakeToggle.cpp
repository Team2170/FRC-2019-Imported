// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Commands/IntakeToggle.h"
#include "Subsystems/Intake.h"
#include "Commands/GotoIntakePosition.h"

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR


IntakeToggle::IntakeToggle(): ConditionalCommand(new GotoIntakePosition, new IntakeUp) {
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

/**
 * @brief This is the condition statement for this conditional command
 * 
 * Depending on the current state of the intake (up or down),
 * the elevator will be sent to the opposite state.
 */
bool IntakeToggle::Condition(){
	return Robot::intake->IsIntakeUp();
}