#include "OI.h"
#include "Commands/Arm/UpOverrideCommand.h"
#include "Commands/Arm/DownCommand.h"
#include "Commands/Catapult/FireCommand.h"
#include "Commands/Drive/BumpCommand.h"
#include "Commands/Drive/SquareCommand.h"

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
    SENSOR_OI(encoder,drive_left);
    SENSOR_OI(encoder,drive_right);

    // Process operator interface input here.
    SENSOR_CUSTOM(joystickbutton,ArmDown,does,WhileHeld,new ArmDownCommand());
    SENSOR_CUSTOM(joystickbutton,Fire,does,WhenPressed,new CatapultFireCommand());
    SENSOR_CUSTOM(joystickbutton,ArmUpOverride,does,WhileHeld,new ArmUpOverrideCommand());
    SENSOR_CUSTOM(joystickbutton,Square,does,WhileHeld,new SquareDriveCommand());
    SENSOR_CUSTOM(joystickbutton,Bump,does,WhenPressed,new BumpDriveCommand());
}
