#include "AutoDrive.h"
#define AUTODRIVE_ENCODER drive_left

// Takes as input left and right functions that take float speed, a dist (encoder untits), angle (degrees), and speed (in (0,1]).
void autoDrive(void (*leftSetPtr)(float),void (*rightSetPtr)(float),float dist,float angle,float speed)
{
    static const float PI = 3.14159265;
    // (1-cos(pi*x))/2 == sin(pi/2*x)^2
    // Distances follow (1-cos(pi*x))/2 (instead of the linear x) from 0 to 1 with rad
    // Therefore the speed is set to the derivative of it, (pi*sin(pi*x))/2 with rad

    // We're actually using sin(180*x) as C does degrees
    // The gyro/encoder will take care of finishing the movement
    // Turn
    SENSOR_CUSTOM(gyro,gyro,Reset);
    angleSign = sign(angle);
    angle = abs(angle);
    float realAngle;
    while ((angleSign * SENSOR_GET(gyro,gyro)) < (angleSign * angle))
    {
        realAngle = SENSOR_GET(gyro,gyro);
        currentSpeed = PI*sin(PI*(realAngle/angle))/2;
        leftSetPtr(angleSign*currentSpeed);
        rightSetPtr(-angleSign*currentSpeed);
    }
    // Move
    while (SENSOR_GET(encoder,AUTODRIVE_ENCODER)<dist)
    {
        realDist = SENSOR_GET(encoder,AUTODRIVE_ENCODER);
        currentSpeed = PI*sin(PI*(realDist/angle))/2;
        if (SENSOR_GET(joystickbutton,Slow)) { currentSpeed /= 2; }
        leftSetPtr(sign(dist)*currentSpeed);
        rightSetPtr(sign(dist)*currentSpeed);
    }
}
