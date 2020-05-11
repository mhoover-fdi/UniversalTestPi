#include <unistd.h>
#include <stdio.h>

#include "../headers/TestModel.h"
#include "../headers/SerialModel.h"
#include "../headers/TestStandard.h"
#include "../headers/BkMeter.h"
#include "../headers/pi_relay_output.h"
#include "../headers/audio.h"


extern struct test_list_data_struct the_test_list_array[199];


void rib_standard(char * the_c_test_name_string, double the_test_number, double the_lo_limit, double the_hi_limit, char * the_c_limit_string)
{
    float       timer = 0;
    int         timed_out = NO;
    char        string_99_buffer[99];
    char        message_99_buffer[99];
    double      measurement;


    switch((int)the_test_number)
    {

        /****************************************************************************************************************************************************************
        *
        *   TEST PAUSE
        *
        ***************************************************************************************************************************************************************/
        case 11000:
            // DISPLAYS THE TEST NAME STRING TO TOP COMMAND BOX ON UI
            test_command(the_c_test_name_string);

            // PAUSES FOR THE TIME GIVEN FROM THE LO LIMIT
            // YES - DISPLAYS COUNT DOWN IN TEST NAME BOX ON BOTTOM OF UI
            // NO  - DOESN'T DISPLAY ANYTHING
            test_pause( the_lo_limit, YES );

            // PASSES THE TEST RESULT OR "measurement" AND EVALUATES IF TEST PASSED OR FAILED BASED ON LIMITS
            result_number(the_lo_limit);
            break;

        /****************************************************************************************************************************************************************
        *
        *   STARTS THE WAV FILE PLAYING
        *
        ***************************************************************************************************************************************************************/
        case 11001:
            // DISPLAYS THE TEST NAME STRING TO TOP COMMAND BOX ON UI
            test_command(the_c_test_name_string);

            sprintf(string_99_buffer,"sudo -b /usr/bin/omxplayer -o local /home/pi/Desktop/UniversalTestPi/UniversalTest/60Hz_Sine.wav --vol %d", the_lo_limit );
            system(string_99_buffer);
            // PASSES THE TEST RESULT OR "measurement" AND EVALUATES IF TEST PASSED OR FAILED BASED ON LIMITS
            result_number(the_lo_limit);
            break;

        /****************************************************************************************************************************************************************
        *
        *   STOPS THE WAV FILE PLAYING
        *
        ***************************************************************************************************************************************************************/
        case 11003:
            // DISPLAYS THE TEST NAME STRING TO TOP COMMAND BOX ON UI
            test_command(the_c_test_name_string);

            system("killall omxplayer.bin");

            // PASSES THE TEST RESULT OR "measurement" AND EVALUATES IF TEST PASSED OR FAILED BASED ON LIMITS
            result_number(the_lo_limit);
            break;


            default:
                sprintf( the_c_limit_string, "RIB Test %d Not Listed", (int)the_test_number);
                test_command(the_c_limit_string);
                test_name(the_c_limit_string);
                break;
    }
}
