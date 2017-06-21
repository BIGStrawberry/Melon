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
    float currentAngle;
    bool clockwise;
    
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
     * @param angle Amount of angle the stepper motor will turn
     */
    void turnDegrees(float angle);
    
    /**
     * @brief Function to turn to a specific angle in a 360 degree circle.
     * @param angle Angle the stepper will turn to 
     */
    void turnToDegree(float angle);
    
    /**
     * @brief Function to check if the motor is set to turn clockwise
     * @return True if it's clockwise, false if not
     */
    bool get_clockwise();
    
    /**
     * @brief Function to set the motor clockwise or counter-clockwise
     * @param clockwise True for clockwise, false for counter-clockwise
     */
    void set_clockwise(bool clockwise);

};


#endif //MELON_STEPPER_HPP