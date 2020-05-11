#include <stdio.h>
#include <string.h>
#include <espeak/speak_lib.h>



int SynthCallback(short *wav, int numsamples, espeak_EVENT *events);
int speakInit(void);
void speakCleanup(void);
//takes in a char array and length, will speak the words
int speak(char * string);
//changes the base pitch, accepts values within 0-100
int changeBasePitch(int newVal);
//changes the range of pitch within the voice accepts values within 0-100, 50 is normal
int changeRangePitch(int newVal);
//changes word speed values should be bwtween 80 and 450
int changeWordSpeed(int newVal);

