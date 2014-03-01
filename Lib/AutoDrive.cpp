#include "AutoDrive.h"

// Takes as input left and right functions that take float speed, a dist (encoder untits), angle (degrees), and speed (in (0,1]).
void autoDrive(std::function<void (float)> leftSet,std::function<void (float)> rightSet,
        std::function<float ()> distGet,
        std::function<float ()> angleGet,
        std::function<float ()> speedGet,
        float dist,float angle)
{
    static const float PI = 3.14159265;
    // (1-cos(pi*x))/2 == sin(pi/2*x)^2
    // Distances follow (1-cos(pi*x))/2 (instead of the linear x) from 0 to 1 with rad
    // Therefore the speed is set to the derivative of it, (pi*sin(pi*x))/2 with rad

    // We're actually using sin(PI*x) as C and need to convert the gyros to rad
    // The gyro/encoder will take care of finishing the movement
    // Turn
    int angleSign = (angle>0)-(angle<0); // sign
    angle = abs(angle);
    float realAngle,currentSpeed;
    while ((angleSign*angleGet()) < angle)
    {
        realAngle = abs(angleGet()*PI/180);
        currentSpeed = sin(PI*realAngle/angle)*speedGet();
        leftSet(angleSign*currentSpeed);
        rightSet(-angleSign*currentSpeed);
    }
    // Move
    int distSign = (dist>0)-(dist<0); // sign
    dist = abs(dist);
    float realDist;
    while ((distSign*distGet())<dist)
    {
        realDist = abs(distGet());
        currentSpeed = sin(PI*(realDist/dist))*speedGet();
        leftSet(distSign*currentSpeed);
        rightSet(distSign*currentSpeed);
    }
}
