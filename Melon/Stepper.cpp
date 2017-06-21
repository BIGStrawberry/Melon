#include "Stepper.hpp"

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
    
float currentAngle = 0.0;
bool clockwise = true;

Stepper::Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4 ):
    pin1(pin1),
    pin2(pin2),
    pin3(pin3),
    pin4(pin4)
{}

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
    if (steps > 0) {
        set_clockwise(true);
        hwlib::cout << "Clockwise?: " << this->get_clockwise() << hwlib::endl;
    } else {
        set_clockwise(false);
        hwlib::cout << "Clockwise?: " << this->get_clockwise() << hwlib::endl;
    }
    
    for (int i = 0; i < steps; ++i) {
        this->step();
    }
}

void Stepper::turnDegrees(float angle) {
    currentAngle = currentAngle + angle;

    hwlib::cout << "Turn Angle: " << (int)angle << "." << hwlib::endl;
    hwlib::cout << "Current Angle: " << (int)currentAngle << "." << hwlib::endl;
    hwlib::cout << "Steps: " << (int)(256 * angle) / 360 << "." << hwlib::endl;
   
    steps((int) (256 * angle) / 360);
}

void Stepper::turnToDegree(float angle) {
    this->turnDegrees(angle-currentAngle);
}

bool Stepper::get_clockwise() {
    return clockwise;
}

void Stepper::set_clockwise(bool clockwise) {
    this->clockwise = clockwise;
}