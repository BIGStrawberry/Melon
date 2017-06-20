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

Stepper::Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4 ):
    pin1(pin1),
    pin2(pin2),
    pin3(pin3),
    pin4(pin4)
{}

void Stepper::step() {
    for (int j = 0; j < 8; ++j) {
        pin1.set(SEQUENCE[j][0]);
        pin2.set(SEQUENCE[j][1]);
        pin3.set(SEQUENCE[j][2]);
        pin4.set(SEQUENCE[j][3]);
        hwlib::wait_ms(3);
    }
}

void Stepper::steps(int steps) {
    for (int i = 0; i < steps; ++i) {
        this->step();
    }
}

void Stepper::angleRotation(float angle) {
    steps( (int)(260 * angle) / 360);
}