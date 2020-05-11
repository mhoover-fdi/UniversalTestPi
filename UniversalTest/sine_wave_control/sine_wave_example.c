/* Noah Smith
 * 2/19/20
 * Functional Devices
 * 
 * Plays sine wave file in background
 * 
 * need modified dbuscontrol.sh executable (chmod u+x dbuscontrol.sh)
 * github.com/popcornmix/omxplayer/issues/458
 * 
 * */

#include <stdio.h>
#include <math.h>
#include <pigpio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include "pi_relay_output.h"


unsigned long long relay_bank_state = 0;

int main ()
{
    init_relay_bank(); //required declaration
    gpioDelay(1000000); //optional
    int pid;
    pid = fork();
    
    if(pid==0)
    {
	    //turn on sine wave in background
	    //starts at an arbitrary volume of "-1800" could be removed
	    execlp("/usr/bin/omxplayer", " ", "-o", "local", "/home/pi/Downloads/60Hz_Sine.wav",  "--vol", "-1800", NULL);
	    _exit(0);
    }
    
    gpioDelay(1000000);
    //turn off sine wave
    system("./dbuscontrol.sh volume 0");
    //turn on relay for step up transformer
    relay(20, 1);
       
    //slowly ramp up sine wave
    char buf[29];
    for (float i = 0; i < 1; i = i + 0.01)
    {
	    snprintf(buf, sizeof(buf), "./dbuscontrol.sh volume %.2f", i);
	    system(buf);
	    gpioDelay(100000);
    }
    
    gpioDelay(3000000);
    //turn off sine wave
    system("killall omxplayer.bin");
    //turn off relay
    relay(20, 0);
    system("reset"); //NDS 2/19/20 for some reason the Pi command line characters are invisible until you reset the command line
}
