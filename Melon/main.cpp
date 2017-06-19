#include "hwlib.hpp"
#include "HCSR04.hpp"
#include "Stepper.hpp"

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
    
    auto trigger_pin3 = hwlib::target::pin_out(hwlib::target::pins::d48);
    auto echo_pin3 = hwlib::target::pin_in(hwlib::target::pins::d49);
    
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

    auto step_pin1 = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto step_pin2 = hwlib::target::pin_out(hwlib::target::pins::d4);
    auto step_pin3 = hwlib::target::pin_out(hwlib::target::pins::d5);
    auto step_pin4 = hwlib::target::pin_out(hwlib::target::pins::d6);
    
//    auto pins = hwlib::port_out_from_pins( step_pin1, step_pin2, step_pin3, step_pin4);

    Stepper stepper(step_pin1, step_pin2, step_pin3, step_pin4);

    /*
     * Create and add all the sensor objects to an array
     */
//    HCSR04 obs[] = { 
//                     HCSR04 (trigger_pin0, echo_pin0, 300),
//                     HCSR04 (trigger_pin1, echo_pin1, 300),
//                     HCSR04 (trigger_pin2, echo_pin2, 300),
//                     HCSR04 (trigger_pin3, echo_pin3, 300),
//                     HCSR04 (trigger_pin4, echo_pin4, 300),
//                     HCSR04 (trigger_pin5, echo_pin5, 300),
//                     HCSR04 (trigger_pin6, echo_pin6, 300),
//                     HCSR04 (trigger_pin7, echo_pin7, 300),
//                     HCSR04 (trigger_pin8, echo_pin8, 300),
//                     };

    while ( 1 ) {   
        //520 is about a 360
        stepper.forwards(512);        
        hwlib::wait_ms(1000);
        stepper.backwards(512);
    
        /*
         * Loop through all the sensor objects
         */
//        for (int i = 0; i < NUM_SENSORS; ++i) {
//            hwlib::cout << "Sensor" << i << " (" << i *30 << "degrees)" << ": " << (uint32_t) obs[i].get_average_distance(3) << ". \n";
//        }
    }
}
