#ifndef MELON_HCSR04_HPP
#define MELON_HCSR04_HPP

#include <hwlib.hpp>
#include "config.hpp"

/**
 * @class HCSR04
 * @author Wouter Dijkstra
 * @date 22-6-2017
 * @file HCSR04.hpp
 * @brief Class for the HCSR04 Ultrasonic Sensor
 */
class HCSR04 {
private:
    hwlib::target::pin_out trigger_pin;
    hwlib::target::pin_in echo_pin;
    
    int termination_zone;
    
public:
    /**
     * @brief HCSR04 Constructor
     * @param trigger_pin       Pin to send the pulse on
     * @param echo_pin          Pin to listen for the reflection on
     * @param termination_zone  Distance to 'trip' the sensor
     */
    HCSR04(hwlib::target::pin_out&trigger_pin, hwlib::target::pin_in& echo_pin, int termination_zone);
    

    /**
     * @brief Function to get the value from a HCSR04 sensor
     * @return distance in CM
     */
    uint32_t get_distance();
    
    /**
     * @brief Function to get an average value from multiple measurements
     * @param samples Amount of samples to use
     * @return distance in CM
     */
    int get_average_distance(int samples);
    
    /**
     * @brief Function to see if something is in the termination zone
     * @param distance uint32_t distance to check if it is in range
     * @return TRUE or FALSE
     */
    bool in_termination_zone();
         
    /**
     * @brief Function to get the termination zone
     * @return termination zone in CM
     */
    int get_termination_zone();
    
    /**
     * @brief Function to set the termination zone
     * @param centimeters distance of the termination zone
     */
    void set_termination_zone(int centimeters);
    
};

#endif //MELON_HCSR04_HPP