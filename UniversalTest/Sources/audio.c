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
#include "../headers/pi_relay_output.h"



uint64_t relay_bank_state = 0;

int audio_output(double volume)
{
    int pid;
    pid = fork();
    char command_buf[256];

    if(pid>0)
    {
	    //turn on sine wave in background
	    //starts at an arbitrary volume of "-1800" could be removed
	    // sprintf( command, "omxplayer -o local giveway.mp3" );
	    sprintf(command_buf,"/usr/bin/omxplayer -o local /home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav --vol 100, NULL");
	    printf("\n%s\n",command_buf);
	  //execlp("/usr/bin/omxplayer", " ", "-o", "local", "/home/pi/Downloads/60Hz_Sine.wav",  "--vol", "-1800", NULL);
	    execlp("/usr/bin/omxplayer", " ", "-o", "local", "/home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav",  "--vol", "100", NULL);
	    //execve("/usr/bin/omxplayer", " ", "-o", "local", "/home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav",  "--vol", "100", NULL);
	    //execlp(command_buf, NULL);
	    _exit(0);
    }

// MTH    gpioDelay(1000000);
    //turn off sine wave
// MTH    system("./dbuscontrol.sh volume 0");
    //turn on relay for step up transformer
    // MTH relay(20, 1);

    //slowly ramp up sine wave
    char buf[256];
    for (float i = 0; i < 1; i = i + 0.01)
    {
	    snprintf(buf, sizeof(buf), "./dbuscontrol.sh volume %.2f", i);
	    printf("\n%s\n",buf);
	    system(buf);
	    gpioDelay(100000);
    }

    // MTH gpioDelay(3000000);
    //turn off sine wave
 // MTH   system("killall omxplayer.bin");
    //turn off relay
    // MTH relay(20, 0);
    // MTH system("reset"); //NDS 2/19/20 for some reason the Pi command line characters are invisible until you reset the command line
}

void *audio_output_thread(void *data)
{
    char command_buf[256];

    sprintf(command_buf,"/usr/bin/omxplayer -o local /home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav --vol 100, NULL");
    printf("\n%s\n",command_buf);
    execlp("/usr/bin/omxplayer", " ", "-o", "local", "/home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav",  "--vol", "100", NULL);
    _exit(0);
}
