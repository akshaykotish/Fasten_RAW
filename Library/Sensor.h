#ifndef MOTORS_H
#define MOTORS_H

#include "Adafruit_VL53L0X.h"
    class Ultrasonic{
        public:
            void set_Echo(int e);
            void set_Trig(int e);
            long get_duration();
            long get_inches();
            long get_cm();
            void Run();
    };

    class IR{
        public:
            void set_pirPin(int e)
            void set pirStat(int e)
            bool Install()
            bool Run()
    };

    class Laser{
        public:
            long Get_mm()
            bool Install()
            long Read_Ranger()
            bool Run()
    };
#endif
