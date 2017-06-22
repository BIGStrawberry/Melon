#include "Laser.hpp"
#include "config.hpp"

Laser::Laser(hwlib::target::pin_out& laserpin):
    laserpin(laserpin)
{}
    
void Laser::turnOn(int time) {
    laserpin.set(1);
    hwlib::wait_ms(time);
    laserpin.set(0);
}