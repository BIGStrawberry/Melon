#include "HCSR04.hpp"
#include "config.hpp"

HCSR04::HCSR04(hwlib::target::pin_out& trigger_pin, hwlib::target::pin_in& echo_pin, int termination_zone):
    trigger_pin(trigger_pin),
    echo_pin(echo_pin),
    termination_zone(termination_zone)    
    {
        termination_zone = TERMINATION_ZONE;
    }

uint32_t HCSR04::get_distance() {
    //Send pulse
    trigger_pin.set(0); 
    hwlib::wait_ms(2);
    trigger_pin.set(1);
    hwlib::wait_ms(10);
    trigger_pin.set(0);
    
    //Receive pulse
    bool received = echo_pin.get();
    
    //Get current time
    int duration = (int) hwlib::now_us();
    
    while (!received)
        received = echo_pin.get();
    while (received)
        received = echo_pin.get();
    
    //Calculate distance
    duration = (int) ((hwlib::now_us() - duration) - DISTANCE_CALIBRATION);
    int distance = (int) ((duration / 2) / 29.1);
    
    //Return MAX_DISTANCE if it exceeds MAX_DISTANCE
    if (distance > MAX_DISTANCE) { return MAX_DISTANCE; }
    
    //Return distance
    return (uint32_t) distance;
}


int HCSR04::get_average_distance(int samples) {
    int total_distance = 0;
    int n_filtered = 0;
    
    for (int i = 0; i < samples; ++i) {
        int distance = get_distance();
        if ( ((total_distance / i) - distance) < 10 ) { //Filters out weird values from the average            
            total_distance += get_distance();
        } else {
            n_filtered++;
        }
    }    
    return total_distance / (samples - n_filtered);
}

bool HCSR04::in_termination_zone(uint32_t distance) {
    return (uint32_t)this->get_termination_zone() > distance;
}

int HCSR04::get_termination_zone() {
    return termination_zone;
}

void HCSR04::set_termination_zone(int centimeters) {
    termination_zone = centimeters;
}