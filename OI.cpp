#include "OI.h"
#include "Commands/ActivateCompressorCommand.h"
#include "Commands/ArmUpCommand.h"
#include "Commands/ArmDownCommand.h"
#include "Commands/Catapult/CatapultFireCommand.h"

OI::OI()
{
    // Use a joystick.
    SENSOR_OI_H(joystick,main);

    // Use sensors.
    SENSOR_OI(gyro,gyro);
    SENSOR_OI(digitalin,compressor);
    SENSOR_OI(digitalin,arm_top);
    SENSOR_OI(digitalin,arm_bot);
    SENSOR_OI(digitalin,catapult);

    // Process operator interface input here.
    SENSOR_CUSTOM(joystickbutton,Compress,does,WhileHeld,new ActivateCompressorCommand());
    SENSOR_CUSTOM(joystickbutton,ArmUp,does,WhileHeld,new ArmUpCommand());
    SENSOR_CUSTOM(joystickbutton,ArmDown,does,WhileHeld,new ArmDownCommand());
    SENSOR_CUSTOM(joystickbutton,Fire,does,WhenPressed,new CatapultFireCommand());
}
