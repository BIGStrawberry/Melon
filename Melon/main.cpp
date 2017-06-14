#include "hwlib.hpp"
#include "HCSR04.hpp"

int main( int argc, char **argv ) {	
    /*
     * Wait for everything to start up, also changes the frequency of the processor.
     */
    hwlib::wait_ms(1000);
    /*
     * Kills the Watchdog
     */
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    /*
     * Set pins for sensors
     */
    auto trigger_pin0 = hwlib::target::pin_out(hwlib::target::pins::d22);
    auto echo_pin0 = hwlib::target::pin_in(hwlib::target::pins::d23);
    
    auto trigger_pin1 = hwlib::target::pin_out(hwlib::target::pins::d24);
    auto echo_pin1 = hwlib::target::pin_in(hwlib::target::pins::d25);
    
    auto trigger_pin2 = hwlib::target::pin_out(hwlib::target::pins::d26);
    auto echo_pin2 = hwlib::target::pin_in(hwlib::target::pins::d27);
    
    auto trigger_pin3 = hwlib::target::pin_out(hwlib::target::pins::d28);
    auto echo_pin3 = hwlib::target::pin_in(hwlib::target::pins::d29);
    
    auto trigger_pin4 = hwlib::target::pin_out(hwlib::target::pins::d30);
    auto echo_pin4 = hwlib::target::pin_in(hwlib::target::pins::d31);
    
    auto trigger_pin5 = hwlib::target::pin_out(hwlib::target::pins::d32);
    auto echo_pin5 = hwlib::target::pin_in(hwlib::target::pins::d33);
    
    auto trigger_pin6 = hwlib::target::pin_out(hwlib::target::pins::d34);
    auto echo_pin6 = hwlib::target::pin_in(hwlib::target::pins::d35);
    
    auto trigger_pin7 = hwlib::target::pin_out(hwlib::target::pins::d36);
    auto echo_pin7 = hwlib::target::pin_in(hwlib::target::pins::d37);
    
    auto trigger_pin8 = hwlib::target::pin_out(hwlib::target::pins::d38);
    auto echo_pin8 = hwlib::target::pin_in(hwlib::target::pins::d39);
    
    auto trigger_pin9 = hwlib::target::pin_out(hwlib::target::pins::d40);
    auto echo_pin9 = hwlib::target::pin_in(hwlib::target::pins::d41);
    
    auto trigger_pin10 = hwlib::target::pin_out(hwlib::target::pins::d42);
    auto echo_pin10 = hwlib::target::pin_in(hwlib::target::pins::d43);
    
    auto trigger_pin11 = hwlib::target::pin_out(hwlib::target::pins::d44);
    auto echo_pin11 = hwlib::target::pin_in(hwlib::target::pins::d45);
    
    
    /*
     * Create and add all the sensor objects to an array
     */
    HCSR04 obs[] = { 
                     HCSR04(trigger_pin0, echo_pin0, 300),
                     HCSR04 (trigger_pin1, echo_pin1, 300),
                     HCSR04 (trigger_pin2, echo_pin2, 300),
//                     HCSR04 (trigger_pin3, echo_pin3, 300),
//                     HCSR04 (trigger_pin4, echo_pin4, 300),
//                     HCSR04 (trigger_pin5, echo_pin5, 300),
//                     HCSR04 (trigger_pin6, echo_pin6, 300),
//                     HCSR04 (trigger_pin7, echo_pin7, 300),
//                     HCSR04 (trigger_pin8, echo_pin8, 300),
//                     HCSR04 (trigger_pin9, echo_pin9, 300),
//                     HCSR04 (trigger_pin10, echo_pin10, 300),
//                     HCSR04 (trigger_pin11, echo_pin11, 300)
                     };

    while ( 1 ) {
        /*
         * Loop through all the sensor objects
         */
        for (int i = 0; i < NUM_SENSORS; ++i) {
            if (i == 1) {
                hwlib::cout << "Sensor" << i << " (" << i *30 << "degrees)" << ": " << (uint32_t) obs[i].get_average_distance(10) << ". \n";
            } else {
                hwlib::cout << "        " << "Sensor" << i << " (" << i *30 << "degrees)" << ": " << (uint32_t) obs[i].get_average_distance(10) << ". \n";
            }
        }

        /*
         * Get values
         */
        //uint32_t distance0 = (uint32_t) distance_sensor0.get_distance();

        /*
         * Print stuff
         */
        //hwlib::cout << "Distance0: " << distance0 << "\n";       
        //hwlib::cout << "Termination zone: " << distance_sensor0.get_termination_zone() << "\n";
    }
}
