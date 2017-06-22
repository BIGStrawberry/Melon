#ifndef MELON_LASER_HPP
#define MELON_LASER_HPP

#include <hwlib.hpp>
#include "config.hpp"

/**
 * @class HCSR04
 * @author Wouter Dijkstra
 * @date 22-6-2017
 * @file Laser.hpp
 * @brief Class for the Laser
 */
class Laser {
private:
    hwlib::target::pin_out laserpin;
        
public:

    /**
     * @brief Laser Constructor
     * @param laserpin - pin on which the laser will be turned on
     */
    Laser(hwlib::target::pin_out& laserpin);
    
    /**
     * @brief Function to turn on the laser
     * @param time - int : time in millseconds the laser will be turned on
     */
    void turnOn(int time);
    
};

#endif //MELON_LASER_HPP