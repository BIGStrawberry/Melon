#ifndef MELON_STEPPER_HPP
#define MELON_STEPPER_HPP

#include <hwlib.hpp>

/**
 * @class Stepper
 * @author Wouter Dijkstra
 * @date 20-6-2017
 * @file Stepper.hpp
 * @brief Class for the 28BYJ-48 Stepper motor
 */
class Stepper {
private:
    hwlib::target::pin_out pin1;
    hwlib::target::pin_out pin2;
    hwlib::target::pin_out pin3;
    hwlib::target::pin_out pin4; 
    
    static const int SEQUENCE[][4];
    
public:
    /**
     * @brief Stepper Constructor
     * @param pin1  PIN1 on the Stepper driver board
     * @param pin2  PIN2 on the Stepper driver board
     * @param pin3  PIN3 on the Stepper driver board
     * @param pin4  PIN4 on the Stepper driver board
     */
    Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4);
    
    
    /**
     * @brief Function to perform a single step
     */
    void step();
    
    /**
     * @brief Function to perform multiple steps 
     * @param steps Amount of steps the stepper motor will turn
     */
    void steps(int steps);
    
    /**
     * @brief Function to rotate the stepper motor in angles
     * @param angle Angle the stepper motor will turn
     */
    void angleRotation(float angle);
};


#endif //MELON_STEPPER_HPP