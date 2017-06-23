//          Copyright Wouter Dijkstra 2017
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include "Stepper.hpp"
#include <Math.h>

const int Stepper::SEQUENCE[][4] = {
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 1, 0, 0, 0 }
    };
    
float currentAngle;
bool clockwise = true;

Stepper::Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4 ):
    pin1(pin1),
    pin2(pin2),
    pin3(pin3),
    pin4(pin4)
    {
        currentAngle = 0;
    }

void Stepper::step() {
    for (int j = 0; j < 8; ++j) {
        if (clockwise) {
            pin1.set(SEQUENCE[j][0]);
            pin2.set(SEQUENCE[j][1]);
            pin3.set(SEQUENCE[j][2]);
            pin4.set(SEQUENCE[j][3]);
            hwlib::wait_ms(3);            
        } else {
            pin1.set(SEQUENCE[j][3]);
            pin2.set(SEQUENCE[j][2]);
            pin3.set(SEQUENCE[j][1]);
            pin4.set(SEQUENCE[j][0]);
            hwlib::wait_ms(3);     
        }
    }
}

void Stepper::steps(int steps) {
    //Check to see if we need to turn clockwise, or counterclockwise
    set_clockwise(steps > 0 ? true : false);
    
    //Make sure the number of steps is positive
    //A negative number of steps are still steps, just in a different direction
    int noOfSteps = fabsf(steps);
    
    //Perform the steps
    for (int i = 0; i < noOfSteps; ++i) {
        this->step();
    }
}

void Stepper::turnDegrees(float angle) {
    //Keep track off what our current angle is
    this->set_current_angle(this->get_current_angle() + angle);

    /* Debugging */
    hwlib::cout << "Turn Angle: " << (int)angle << "." << hwlib::endl;
    hwlib::cout << "Current Angle: " << (int)currentAngle << "." << hwlib::endl;
    hwlib::cout << "Steps: " << (int)(256 * angle) / 360 << "." << hwlib::endl;
    /* Debugging */
    
    //Calculate how many steps are needed to turn an X amount of degrees
    steps((int) (256 * angle) / 360);
}

void Stepper::turnToDegree(float angle) {    
    this->turnDegrees(angle-currentAngle);
}

void Stepper::turnToSensor(int sensor_id) {
    this->turnToDegree(sensor_id * 40);
}

bool Stepper::get_clockwise() {
    return clockwise;
}

void Stepper::set_clockwise(bool clockwise) {
    this->clockwise = clockwise;
}

float Stepper::get_current_angle() {
    return currentAngle;
}

void Stepper::set_current_angle(float angle) {
    this->currentAngle = angle;
}