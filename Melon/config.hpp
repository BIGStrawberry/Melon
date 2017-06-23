//          Copyright Wouter Dijkstra 2017
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MELON_CONFIG_H
#define MELON_CONFIG_H

//Config file with all the constants
#define NUM_SENSORS 9 /* Number of HCSR04 sensors used */
#define DISTANCE_CALIBRATION 400 /* MS - Distance calibration now_us was 400ms offset */
#define MAX_DISTANCE 400 /* CM - Maximum distance */
#define TERMINATION_ZONE 20 /* CM - Distance the sensors will trigger on */
#define DEFAULT_LASER_TIME 2000 /* MS - Milliseconds it'll turn on the laser */

#endif //MELON_CONFIG_H