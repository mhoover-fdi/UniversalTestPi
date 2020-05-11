
/* Noah Smith
 * 2/10/20
 * Functional Devices
 *
 * Allrib Tester Raspberry Pi I/O board
 * Initializes shift registers and toggles desired relay
 * */

 // MTH Integrated into UniversalTest and added error feedback

//gcc -Wall -pthread -o <name> <name> -lpigpio -lm

#include <stdio.h>
#include <math.h>
#include <pigpio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/pi_relay_output.h"

uint64_t relay_bank_state; //45 relays = 45 bits

int init_relay_bank( void )
{
    int error = 1;

    if(error = gpioInitialise()<0)
        return error;

    if(error = gpioSetMode(DATA, PI_OUTPUT) < 0)
        return error;
    if(error = gpioSetMode(MR, PI_OUTPUT) < 0)
        return error;
    if(error = gpioSetMode(ST_CP, PI_OUTPUT) < 0)
        return error;
    if(error = gpioSetMode(SH_CP, PI_OUTPUT) < 0)
        return error;
    if(error = gpioSetMode(OE, PI_OUTPUT) < 0)
        return error;

    if(error = gpioWrite(OE, 0) < 0)
        return error;
    if(error = gpioWrite(MR, 1) < 0)
        return error;

    if(error = gpioWrite(ST_CP, 0) < 0)
        return error;
    if(error = gpioWrite(MR, 0) < 0)
        return error; //shift in 0's
    if(error = gpioWrite(ST_CP, 1) < 0)
        return error;
    if(error = gpioWrite(MR, 1) < 0)
        return error;
    if(error = gpioWrite(ST_CP, 0) < 0)
        return error;

    relay_bank_state = 0ULL;

    return 0;
}

// relay(34, 1) turns relay 34 ON
// There are relays 1 to 45
int relay( int relay_number, int relay_state)
{
    int error = 1;

    // Check relay state
    if ((relay_bank_state >> (relay_number - 1)) & relay_state)
    {
        return;
    }
    else
    {
        // desired relay binary conversion
        uint64_t relay_number_bit = (1ULL<<(relay_number - 1));

        // add if turning relay on, subtract if turning relay off
        if (relay_state == 1)
        {
            relay_bank_state += relay_number_bit;
        }
        else
        {
            relay_bank_state -= relay_number_bit;
        }
    }

    // Shift into memory of 45 relays
    for (int i = 44; i >= 0; i--)
    {
        if(error = gpioWrite(DATA, ((relay_bank_state >> i) & 1))<0)
            return error;
        if(error = gpioWrite(SH_CP, 0)<0)
            return error;
        if(error = gpioWrite(SH_CP, 1)<0)
            return error;
    }

    // Output
    if(error = gpioWrite(ST_CP, 1)<0)
        return error;
    if(error = gpioWrite(ST_CP, 0)<0)
        return error;
}
