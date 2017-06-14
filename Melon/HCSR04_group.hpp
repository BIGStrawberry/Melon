#ifndef MELON_HCSR04_GROUP_HPP
#define MELON_HCSR04_GROUP_HPP

#include <hwlib.hpp>
#include "HCSR04.hpp"
#include "config.hpp"

class HCSR04_group {
private:
   uint_fast8_t _number_of_sensors;  
   
public:
    /*
     * Constructor
     */
    HCSR04_group(
      HCSR04 & h0 = hcsr04_dummy,
      HCSR04 & h1 = hcsr04_dummy,
      HCSR04 & h2 = hcsr04_dummy,
      HCSR04 & h3 = hcsr04_dummy,
      HCSR04 & h4 = hcsr04_dummy,
      HCSR04 & h5 = hcsr04_dummy,
      HCSR04 & h6 = hcsr04_dummy,
      HCSR04 & h7 = hcsr04_dummy,
      HCSR04 & h8 = hcsr04_dummy,
      HCSR04 & h9 = hcsr04_dummy,
      HCSR04 & h10 = hcsr04_dummy,
      HCSR04 & h11 = hcsr04_dummy,
      
   ):
      sensors{ &h0, &h1, &h2, &h3, &h4, &h5, &h6, &hs7, &hs8, &hs9, &hs10, &hs11 }
   {
      for( _number_of_sensors = 0; _number_of_sensors < 12; ++_number_of_sensors ){
         if( sensors[ _number_of_sensors ] == & hcsr04_dummy ){
             break;
         }            
      }
   } 
    

    
};

#endif //MELON_HCSR04_GROUP_HPP