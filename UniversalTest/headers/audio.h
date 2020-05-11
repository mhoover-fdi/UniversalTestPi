/* Noah Smith
 * 2/10/20
 * Functional Devices
 *
 * Allrib Tester Raspberry Pi I/O board
 * Initializes shift registers and toggles desired relay
 * */

//gcc -Wall -pthread -o pi_relay_output_example pi_relay_output_example.c pi_relay_output.c -lpigpio -lm

//#include <stdio.h>
//#include <math.h>
//#include <pigpio.h>
//#include <stdlib.h>
//#include <stdint.h>
#ifndef PI_RELAY_OUTPUT_H_INCLUDED
#define PI_RELAY_OUTPUT_H_INCLUDED

#define DATA 24
#define MR 18
#define ST_CP 23
#define SH_CP 16
#define OE 25

//extern uint64_t relay_bank_state; //45 relays = 45 bits

int audio_output(double volume);


#endif
