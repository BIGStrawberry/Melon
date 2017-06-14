#ifndef MELON_28BYJ48_HPP
#define MELON_28BYJ48_HPP

#include <hwlib.hpp>
#include "config.hpp"

class 28BYJ48 {
private:
    hwlib::target::pin_out PIN1;
    hwlib::target::pin_out PIN2;
    hwlib::target::pin_out PIN3;
    hwlib::target::pin_out PIN4;
        
public:
    /*
     * Constructor
     */
    28BYJ48(hwlib::target::pin_out& PIN1, hwlib::target::pin_out& PIN2, hwlib::target::pin_out& PIN3, hwlib::target::pin_out& PIN4);
    
    
};

#endif //MELON_28BYJ48_HPP