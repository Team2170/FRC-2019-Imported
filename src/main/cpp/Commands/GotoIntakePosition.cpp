// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.



#include "Commands/GotoIntakePosition.h"
#include "Commands/IntakeDown.h"
#include "Commands/ElevatorInnerPos.h"
#include "Commands/ElevatorOuterPos.h"
#include "Commands/ElevatorInnerOuterPos.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

/**
 * @brief Construct a new Goto Intake Position:: Goto Intake Position object
 * 
 * This is a command group that (sequentially):
 *    1. Brings the intake down (for cargo pickup)
 *    2. Sets the inner and outer elevator positions for ball intake
 *       (positions preset as constants in Elevator class).
 */
GotoIntakePosition::GotoIntakePosition() {
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
     // Add Commands here:
    // e.g. AddSequential(new Command1());
    //      AddSequential(new Command2());
    // these will run in order.

    // To run multiple commands at the same time,
    // use AddParallel()
    // e.g. AddParallel(new Command1());
    //      AddSequential(new Command2());
    // Command1 and Command2 will run in parallel.

    // A command group will require all of the subsystems that each member
    // would require.
    // e.g. if Command1 requires chassis, and Command2 requires arm,
    // a CommandGroup containing them would require both the chassis and the
    // arm.
  AddSequential(new IntakeDown());
//  AddSequential(new ElevatorInnerOuterPos(Robot::elevator->kInnerHome, Robot::elevator->kOuterHome));    // 0.5" off ground
  AddSequential(new ElevatorInnerOuterPos(Robot::elevator->kInnerHome, 2.0));    // 0.5" off ground
}
