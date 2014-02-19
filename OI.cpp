#include "OI.h"
#include "Commands/ActivateCompressorCommand.h"
#include "Commands/ArmUpCommand.h"
#include "Commands/ArmDownCommand.h"
#include "Commands/Catapult/CatapultFireCommand.h"

OI::OI()
{
    // Use a controller.
#include "controller/xbox"

    // Use sensors.
    SENSOR_OI(gyro,gyro);
    SENSOR_OI(digitalin,compressor);
    SENSOR_OI(digitalin,arm_top);
    SENSOR_OI(digitalin,arm_bot);
    SENSOR_OI(digitalin,catapult);

    // Process operator interface input here.
    buttonCompress->WhileHeld(new ActivateCompressorCommand());
    buttonArmUp->WhileHeld(new ArmUpCommand());
    buttonArmDown->WhileHeld(new ArmDownCommand());
    buttonFire->WhenPressed(new CatapultFireCommand());
}
