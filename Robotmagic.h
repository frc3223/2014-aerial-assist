#ifndef ROBOTMAGIC_H
#define ROBOTMAGIC_H

/**
 * The Robotmagic used to be just a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 * 
 * Now it's a mix of 200 proof awesome and preprocessor magic.
 */

#define NEWMOTOR(name) (new MOTOR_##name##_TYPE(MOTOR_##name##_MODULE,MOTOR_##name##_CHANNEL))

#define OI_VAR                        oi

#define ANALOG_MODULE                 1
#define DIGITAL_MODULE                1
#define SOLENOID_MODULE               1

#define JAGUAR_1_CHANNEL              1
#define JAGUAR_2_CHANNEL              2
#define JAGUAR_3_CHANNEL              3
#define JAGUAR_4_CHANNEL              4
#define  TALON_1_CHANNEL              5

#define DRIVE_MODULE                  DIGITAL_MODULE
#define MOTOR_right1_MODULE           DRIVE_MODULE
#define MOTOR_right1_CHANNEL          JAGUAR_4_CHANNEL
#define MOTOR_right1_TYPE             Jaguar
#define MOTOR_right2_MODULE           DRIVE_MODULE
#define MOTOR_right2_CHANNEL          JAGUAR_3_CHANNEL
#define MOTOR_right2_TYPE             Jaguar
#define MOTOR_left1_MODULE            DRIVE_MODULE
#define MOTOR_left1_CHANNEL           JAGUAR_1_CHANNEL
#define MOTOR_left1_TYPE              Jaguar
#define MOTOR_left2_MODULE            DRIVE_MODULE
#define MOTOR_left2_CHANNEL           JAGUAR_2_CHANNEL
#define MOTOR_left2_TYPE              Jaguar

#define MOTOR_arm_MODULE              DIGITAL_MODULE
#define MOTOR_arm_CHANNEL             TALON_1_CHANNEL
#define MOTOR_arm_TYPE                Talon
#define ARM_SWITCH_MODULE             DIGITAL_MODULE
#define digitalin_arm_top_MODULE      ARM_SWITCH_MODULE
#define digitalin_arm_top_CHANNEL     2
#define digitalin_arm_bot_MODULE      ARM_SWITCH_MODULE
#define digitalin_arm_bot_CHANNEL     3

#define COMPRESSOR_RELAY_MODULE       DIGITAL_MODULE
#define COMPRESSOR_RELAY_CHANNEL      2
#define digitalin_compressor_MODULE   DIGITAL_MODULE
#define digitalin_compressor_CHANNEL  1

#define CATAPULT_MODULE               SOLENOID_MODULE
#define CATAPULT_1_FORWARD_CHANNEL    3 // Prime
#define CATAPULT_1_REVERSE_CHANNEL    4 // Retract
#define CATAPULT_2_FORWARD_CHANNEL    5 // Lock
#define CATAPULT_2_REVERSE_CHANNEL    6 // Fire
#define digitalin_catapult_MODULE     DIGITAL_MODULE
#define digitalin_catapult_CHANNEL    4

#include "sensor/joystick"
#include "sensor/joystickbutton"
#include "joystick/xbox"
#define joystick_drive_STARTPORT      1

#include "Lib/Sensor.h"
#include "sensor/gyro"
#include "sensor/encoder"
#include "sensor/digitalin"
#include "sensor/var"

#define gyro_gyro_MODULE              ANALOG_MODULE
#define gyro_gyro_CHANNEL             2

#define ENCODER_drive_MODULE          DIGITAL_MODULE
#define ENCODER_drive_PULSEDIST       1
#define ENCODER_drive_REVERSE         true
#define encoder_drive_left_MODULE     ENCODER_drive_MODULE
#define encoder_drive_left_CHANNEL_A  5
#define encoder_drive_left_CHANNEL_B  6
#define encoder_drive_left_REVERSE    ENCODER_drive_REVERSE
#define encoder_drive_left_PULSEDIST  ENCODER_drive_PULSEDIST
#define encoder_drive_right_MODULE    ENCODER_drive_MODULE
#define encoder_drive_right_CHANNEL_A 7
#define encoder_drive_right_CHANNEL_B 8
#define encoder_drive_right_REVERSE   ENCODER_drive_REVERSE
#define encoder_drive_right_PULSEDIST ENCODER_drive_PULSEDIST
#define AUTODRIVE_ENCODER             drive_left

#endif

