#include "Stepper.hpp"

Stepper::Stepper(hwlib::target::pin_out &pin1, hwlib::target::pin_out &pin2, hwlib::target::pin_out &pin3, hwlib::target::pin_out &pin4 ):
    pin1(pin1),
    pin2(pin2),
    pin3(pin3),
    pin4(pin4)
{}

void Stepper::forwards(int steps) {
    for (int i = 0; i < steps; ++i) {
        // 1
        pin4.set(1);
        pin3.set(0);
        pin2.set(0);
        pin1.set(0);
        hwlib::wait_ms(1);
        // 2
        pin4.set(1);
        pin3.set(1);
        pin2.set(0);
        pin1.set(0);
        hwlib::wait_ms(1);
        // 3
        pin4.set(0);
        pin3.set(1);
        pin2.set(0);
        pin1.set(0);
        hwlib::wait_ms(1);
        // 4
        pin4.set(0);
        pin3.set(1);
        pin2.set(1);
        pin1.set(0);
        hwlib::wait_ms(1);
        // 5
        pin4.set(0);
        pin3.set(0);
        pin2.set(1);
        pin1.set(0);
        hwlib::wait_ms(1);
        // 6
        pin4.set(0);
        pin3.set(0);
        pin2.set(1);
        pin1.set(1);
        hwlib::wait_ms(1);
        // 7
        pin4.set(0);
        pin3.set(0);
        pin2.set(0);
        pin1.set(1);
        hwlib::wait_ms(1);
        // 8
        pin4.set(1);
        pin3.set(0);
        pin2.set(0);
        pin1.set(1);
        hwlib::wait_ms(1);
    }
}

void Stepper::backwards(int steps) {
    // 1
    pin1.set(1);
    pin2.set(0);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 2
    pin1.set(1);
    pin2.set(1);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 3
    pin1.set(0);
    pin2.set(1);
    pin3.set(0);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 4
    pin1.set(0);
    pin2.set(1);
    pin3.set(1);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 5
    pin1.set(0);
    pin2.set(0);
    pin3.set(1);
    pin4.set(0);
    hwlib::wait_ms(1);
    // 6
    pin1.set(0);
    pin2.set(0);
    pin3.set(1);
    pin4.set(1);
    hwlib::wait_ms(1);
    // 7
    pin1.set(0);
    pin2.set(0);
    pin3.set(0);
    pin4.set(1);
    hwlib::wait_ms(1);
    // 8
    pin1.set(1);
    pin2.set(0);
    pin3.set(0);
    pin4.set(1);
    hwlib::wait_ms(1);
}