#ifndef MOTORS_H
#define MOTORS_H

#include "Stepper.h"
#include "Servo.h"

    class Servo_Control{
        public:
            Servo servo;
            void set_angle(int e);
            void set_pin(int e);
            void attach();
            void Write();
            void Write(int angle);
            void Write(int angle, int pin);
    };

    class Stepper_Control{
        public:
            void Set_Steps(int e);
            void Set_Pin(int A, int B);
            void Set_Pin(int A, int B, int C, int D);
            void Set_Pin(int A, int B, int C, int D, int E);
            void Set_Speed(int e);
            void for_2_pin();
            void for_4_pin();
            void for_5_pin();
    };
#endif
