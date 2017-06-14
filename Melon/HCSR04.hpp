#ifndef MELON_HCSR04_HPP
#define MELON_HCSR04_HPP

#include <hwlib.hpp>
#include "config.hpp"

class HCSR04 {
private:
    hwlib::target::pin_out trigger_pin;
    hwlib::target::pin_in echo_pin;
    
    int termination_zone = MAX_DISTANCE;
    
public:
    /*
     * Constructor
     */
    HCSR04(hwlib::target::pin_out&trigger_pin, hwlib::target::pin_in& echo_pin, int termination_zone);
    
    /*
     * Returns the distance in CM
     */
    uint32_t get_distance();
    
    /*
     *  Return the average range from N samples
     */
    
    int get_average_distance(int samples);
    /*
     * Returns TRUE if something is in range of the sensor
     */
    bool in_range();
    
    /*
     * Getter & setter
     */
    int get_termination_zone();
    void set_termination_zone(int centimeters);
    
};

#endif //MELON_HCSR04_HPP