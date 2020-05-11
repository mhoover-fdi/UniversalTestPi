/* Noah Smith
 * 2/10/20
 * Functional Devices
 * 
 * Flips relay to desired state
 * */

#include <stdio.h>
#include <math.h>
#include <pigpio.h>
#include <stdlib.h>
#include <stdint.h>
#include "pi_relay_output.h"


unsigned long long relay_bank_state = 0;

int main ()
{
    init_relay_bank(); //required declaration
    gpioDelay(1000000); //optional
    for(int i = 0; i < 45; i++)
    {
	relay(i, 1); //turns on relays on
    }
}