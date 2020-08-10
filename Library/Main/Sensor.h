#ifndef MOTORS_H
#define MOTORS_H

#include "VL53L0X.h"
    class Ultrasonic{
        public:
            void set_Echo(int e);
            void set_Trig(int e);
            String get_duration();
            String get_inches();
            String get_cm();
            void Run();
    };

    class IR{
        public:
            void set_pirPin(int e);
            void set_pirState(int e);
            bool Install();
            bool Run();
    };

    class Laser{
        public:
            String Get_mm();
            bool Install();
            String Read_Ranger();
            bool Run();
    };
#endif
