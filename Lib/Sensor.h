#ifndef SENSOR_3223_H
#define SENSOR_3223_H

#include "../Robotmagic.h"

#define SENSOR_OI(sensor,name,...) SENSOR_##sensor##_OI(name,##__VA_ARGS__)
#define SENSOR_OI_H(sensor,name,...) SENSOR_##sensor##_OI_H(name,##__VA_ARGS__)
#define SENSOR_GET(sensor,name,...) SENSOR_##sensor##_GET(name,##__VA_ARGS__)
#define SENSOR_SET(sensor,name,value,...) SENSOR_##sensor##_##value##_SET(name,##__VA_ARGS__)
#define SENSOR_CUSTOM(sensor,name,action,...) SENSOR_##sensor##_##action##(name,##__VA_ARGS__)

#endif
