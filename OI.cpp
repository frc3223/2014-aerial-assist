#include "OI.h"
#include "Commands/ActivateCompressorCommand.h"
#include "Commands/Arm/UpCommand.h"
#include "Commands/Arm/DownCommand.h"
#include "Commands/Catapult/FireCommand.h"

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
    SENSOR_OI(encoder,left);
    SENSOR_OI(encoder,right);

    // Process operator interface input here.
    SENSOR_CUSTOM(joystickbutton,Compress,does,WhileHeld,new ActivateCompressorCommand());
    SENSOR_CUSTOM(joystickbutton,ArmUp,does,WhileHeld,new ArmUpCommand());
    SENSOR_CUSTOM(joystickbutton,ArmDown,does,WhileHeld,new ArmDownCommand());
    SENSOR_CUSTOM(joystickbutton,Fire,does,WhenPressed,new CatapultFireCommand());
}
