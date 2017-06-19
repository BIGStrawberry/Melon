#ifndef MELON_STEPPER_HPP
#define MELON_STEPPER_HPP
#include <hwlib.hpp>

class Stepper {
private:
    hwlib::target::pin_out pin1;
    hwlib::target::pin_out pin2;
    hwlib::target::pin_out pin3;
    hwlib::target::pin_out pin4; 
    
public:
    Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4);
    void backwards(int steps);
    void forwards(int steps);
};


#endif //MELON_STEPPER_HPP