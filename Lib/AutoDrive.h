#include <math.h>
#include <functional>
#include "../OI.h"
#include "../Robotmagic.h"

void autoDrive(std::function<void (float)> leftSet,std::function<void (float)> rightSet,
        std::function<float ()> distGet,
        std::function<float ()> angleGet,
        std::function<float ()> speedGet,
        float dist,float angle);
