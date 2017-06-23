//          Copyright Wouter Dijkstra 2017
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

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