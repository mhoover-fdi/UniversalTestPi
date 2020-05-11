#include <unistd.h>
#include <stdio.h>

#include "../headers/TestModel.h"
#include "../headers/SerialModel.h"
#include "../headers/TestStandard.h"
#include "../headers/BkMeter.h"
#include "../headers/pi_relay_output.h"


#define NA (9999)
#define SERVICE_ACK_BYTE (2)
#define PD_OPENING_TAG_3_BYTE (20)
#define PROPERTY_LENGTH_BYTE (22)
#define FDI_DEVICE_ID (277000)
#define DEVICE_OBJECT_TYPE_ID (8)


extern struct test_list_data_struct the_test_list_array[199];


extern int global_baud;
extern char BACnet_Address[];

char char_response_buffer[99];
char app_sw_version_str[32];
char fw_revision_number_str[32];
char lj_error_buffer[45];

void test_standard(char * the_c_test_name_string, double the_test_number, double the_lo_limit, double the_hi_limit, char * the_c_limit_string)
{
    float       timer = 0;
    int         timed_out = NO;
    char        string_99_buffer[99];
    char        message_99_buffer[99];
    double      measurement;
    double      dummy = 0;
    int         switch_result[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    long        l_num_bytes = 0;
    long        i_o_State = 0;
    long        back_off_state = 0;
    double      LJM_i_o_State = 0;
    long        new_state;
    int         tries = 0;
    int         x = 0;
    int         y = 0;
    int         erR;
    char        *naME;
    uint8_t     index = 0;
    uint8_t     cntr  = 0;
    uint8_t     object_id[4] = {0,0,0,0};
    uint16_t    BACnet_Addr_Int = 0;
    int         error;

    union
    {
        float fv;
        struct
        {
        #if __BIG_ENDIAN__
            uint8_t b_3;
            uint8_t b_2;
            uint8_t b_1;
            uint8_t b_0;
        #else
            uint8_t b_0;
            uint8_t b_1;
            uint8_t b_2;
            uint8_t b_3;
        #endif
        } bytes;
    } u;

    union
    {
        uint16_t w;
        struct
        {
        #if __BIG_ENDIAN__
            uint8_t b_1;
            uint8_t b_0;
        #else
            uint8_t b_0;
            uint8_t b_1;
        #endif
        } bytes;
    } b;

    union
    {
        int16_t w;
        struct
        {
        #if __BIG_ENDIAN__
            uint8_t b_1;
            uint8_t b_0;
        #else
            uint8_t b_0;
            uint8_t b_1;
        #endif
        } bytes;
    } bb;


    test_name("");

    switch((int)the_test_number)
    {
        case    10000:
                test_command(the_c_test_name_string);
                //speak_string(the_c_test_name_string);
                test_pause( the_lo_limit, YES );
                result_number(the_lo_limit);
                break;

        /***************************************************************************************************************************************************************
        *
        *   SET LabJack t4 Analog Output to Limit
        *
        ***************************************************************************************************************************************************************/
        case    10099:
                test_command(the_c_test_name_string);

/*
                erR = LJM_Open((int)LJM_dtT4, LJM_ctUSB, "LJM_idANY", &hDeviceDAC);
                ErrorCheck(erR, "LJM_Open");
                if(erR != 0 )
                {
                    //ErrorToString(lj_error_buffer,erR);
                    sprintf(lj_error_buffer, "LabJack T4 Error message = %d",erR);
                    //MessagePopup("Error", lj_error_buffer);
                }

                erR = LJM_eWriteName((int)hDeviceDAC, nAME, the_lo_limit);
                ErrorCheck(erR, "LJM_eWriteName");
                erR = LJM_Close((int)hDeviceDAC);
                ErrorCheck(erR, "LJM_Close");
*/

                result_number( the_lo_limit );
                break;

		/***************************************************************************************************************************************************************
        *
        *   DMM I/O ON or OFF - LO LIMIT IS OUTPUT NUMBER AND HI LIMIT IS ON OR OFF
        *
        ***************************************************************************************************************************************************************/
        case    10100:
                test_command(the_c_test_name_string);

                //open_lab_jacks();

                switch( (int)the_hi_limit )
                {                         // eDO(LJ_HANDLE Handle, long Channel, long State);
/*                  case FIO0: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO1: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO2: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO3: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO4: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO5: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO6: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case FIO7: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;

                    case EIO0: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO1: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO2: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO3: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO4: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO5: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO6: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case EIO7: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;

                    case CIO0: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case CIO1: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case CIO2: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break;
                    case CIO3: measurement = eDO(HandleDMM(), 0, the_hi_limit, (long)!the_lo_limit );break; */
                }

                if( the_lo_limit == 0 )
                {
                    //eDI(HandleDMM(), 0, the_hi_limit, &new_state);
                }

                //close_lab_jacks();

                test_name( the_c_test_name_string );

                // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
                if(measurement == 0 )
                {
                    result_number( the_lo_limit );
                }
                else
                {
                    result_number( measurement );
                }
                break;

        /****************************************************************************************************************************************************************
         *
         *   JIG I/O ON or OFF - LO LIMIT IS OUTPUT NUMBER AND HI LIMIT IS ON OR OFF
         *
         ***************************************************************************************************************************************************************/
        case    10101:
                test_command(the_c_test_name_string);

                error = relay( the_hi_limit, the_lo_limit);

                test_name( the_c_test_name_string );

                if(error < 0)
                {
                    result_number(error);
                }
                else
                {
                    result_number( the_lo_limit );
                }

                break;

        /****************************************************************************************************************************************************************
         *
         *   JIG I/O READ INPUT - HI LIMIT IS CHANNEL NUMBER TO READ
         *   CIO0    16
         *   CIO1    17
         *   CIO2    18
         *   CIO3    19
         *
         ***************************************************************************************************************************************************************/
        case    10102:
                test_command(the_c_test_name_string);

                //open_lab_jacks();

                test_name( the_c_test_name_string );

                measurement = 0;
                timer = 10; //  30;
                timed_out = NO;
                tries = 0;

                do
                {
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting for Switch I/O %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                    //measurement = eDI(HandleJIG(), 0, the_hi_limit, &i_o_State );

                    if( i_o_State == the_lo_limit )
                    {
                        ++tries;
                    }

                }
                while( (timer >= 0) && (tries < 3) );

                //close_lab_jacks();

                if( the_lo_limit != i_o_State )
                {
                    result_number( -1 );
                }
                else
                {
                    result_number( i_o_State );
                }

                break;

        /****************************************************************************************************************************************************************
        *
        *   SPEAK TO OPERATOR
        *
        ***************************************************************************************************************************************************************/
        case    10109:
                test_command(the_c_test_name_string);
                speak_string(the_c_test_name_string);

                result_number(0);
                break;

        /****************************************************************************************************************************************************************
        *
        *   APPLY -20V
        *
        ***************************************************************************************************************************************************************/
        case    10200:
                test_command(the_c_test_name_string);
                test_name( the_c_test_name_string );
            //[[NSNotificationCenter defaultCenter] postNotificationName:@"open_lab_jack" object:nil];
            //open_lab_jacks();

            // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
            //measurement = eDO(HandleJIG(), 0, FIO4, (long)0 );
            //measurement = eDO(HandleJIG(), 0, EIO2, (long)0 );

            //[[NSNotificationCenter defaultCenter] postNotificationName:@"close_lab_jack" object:nil];
            //close_lab_jacks();

                if (measurement == 0)
                {
                    result_number(the_lo_limit);
                }
                else
                {
                    result_number(measurement);
                }
                break;

        /****************************************************************************************************************************************************************
        *
        *   APPLY 0V
        *
        ***************************************************************************************************************************************************************/
        case    10202:
                test_command(the_c_test_name_string);
                test_name( the_c_test_name_string );
            //open_lab_jacks();

            // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
            //measurement = eDO(HandleJIG(), 0, FIO6, (long)1 );
            //measurement = eDO(HandleJIG(), 0, FIO4, (long)1 );
            //measurement = eDO(HandleJIG(), 0, EIO2, (long)1 );
            //measurement = eDO(HandleJIG(), 0, EIO3, (long)1 );
            //measurement = eDO(HandleJIG(), 0, FIO5, (long)1 );
            //measurement = eDO(HandleJIG(), 0, EIO0, (long)1 );

            //close_lab_jacks();

                if (measurement == 0)
                {
                    result_number( the_lo_limit );
                }
                else
                {
                    result_number( measurement );
                }
                break;

        /****************************************************************************************************************************************************************
        *
        *   APPLY +30V
        *
        ***************************************************************************************************************************************************************/
        case    10204:
                test_command(the_c_test_name_string);
                test_name( the_c_test_name_string );
            //open_lab_jacks();

            // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
            //measurement = eDO(HandleJIG(), 0, FIO5, (long)0 );
            //measurement = eDO(HandleJIG(), 0, EIO2, (long)0 );
            //measurement = eDO(HandleJIG(), 0, FIO4, (long)0 );

            //close_lab_jacks();

                if (measurement == 0)
                {
                    result_number( the_lo_limit );
                }
                else
                {
                    result_number( measurement );
                }
                break;

        /****************************************************************************************************************************************************************
        *
        *   APPLY 120V
        *
        ***************************************************************************************************************************************************************/
        case    10206:
                test_command(the_c_test_name_string);
                test_name( the_c_test_name_string );
            //open_lab_jacks();

            // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
            //measurement = eDO(HandleJIG(), 0, EIO0, (long)0 );
            //measurement = eDO(HandleJIG(), 0, EIO3, (long)0 );
            //measurement = eDO(HandleJIG(), 0, FIO4, (long)0 );

            //close_lab_jacks();

                if (measurement == 0)
                {
                    result_number(the_lo_limit);
                }
                else
                {
                    result_number(measurement);
                }
                break;

        /****************************************************************************************************************************************************************
        *
        *   APPLY 208V
        *
        ***************************************************************************************************************************************************************/
        case    10207:
                test_command( the_c_test_name_string );
                test_name( the_c_test_name_string );

            //open_lab_jacks();

            // MEASUREMENT IS 0 IF NO ERROR, OR IS -1 IF ERROR RETURNED FROM eDO FUNCTION FOR U3 I/O
            //measurement = eDO(HandleJIG(), 0, FIO6, (long)0 );
            //measurement = eDO(HandleJIG(), 0, EIO0, (long)0 );
            //measurement = eDO(HandleJIG(), 0, EIO3, (long)0 );
            //measurement = eDO(HandleJIG(), 0, FIO4, (long)0 );

            //close_lab_jacks();

                if (measurement == 0)
                {
                    result_number(the_lo_limit);
                }
                else
                {
                    result_number(measurement);
                }
                break;

        /****************************************************************************************************************************************************************
        *
        *   JIG I/O READ INPUT - HI LIMIT IS CHANNEL NUMBER TO READ
        *   EIO0    8
        *   EIO1    9
        *   EIO2    10
        *   EIO3    11
        *   EIO4    12
        *   EIO5    13
        *   CIO2    18
        *   CIO3    19
        *
        ***************************************************************************************************************************************************************/
        case    10208:
                test_command( the_c_test_name_string );
                test_name( the_c_test_name_string );

            //erR = LJM_Open(LJM_dtT4, LJM_ctUSB, "LJM_idANY", &hDeviceDAC);
                if(erR != 0 )
                {
                    sprintf(lj_error_buffer, "LabJack T4 Error Code = %d",erR);
                }

                switch((int)the_hi_limit)
                {
/*                  case EIO0:naME = "EIO0"; break;
                    case EIO1:naME = "EIO1"; break;
                    case EIO2:naME = "EIO2"; break;
                    case EIO3:naME = "EIO3"; break;
                    case EIO4:naME = "EIO4"; break;
                    case EIO5:naME = "EIO5"; break;
                    case EIO6:naME = "EIO6"; break;
                    case EIO7:naME = "EIO7"; break;
                    case CIO0:naME = "CIO0"; break;
                    case CIO1:naME = "CIO1"; break;
                    case CIO2:naME = "CIO2"; break;
                    case CIO3:naME = "CIO3"; break; */
                }

                if(get_debug_mode())
                    printf("\nWriting %f to %s\n", the_hi_limit, naME);

                measurement = 0;
                timer = 20; //  30;
                timed_out = NO;
                tries = 0;

                do
                {
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting for Switch I/O %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                //measurement = eDI(hDeviceDAC, 0, the_hi_limit, &i_o_State );

                // Read DIO state from the LabJack
                //erR = LJM_eReadName(hDeviceDAC, naME, &LJM_i_o_State);

                //printf("\n%s state : %f\n", naME, LJM_i_o_State);

                    if( LJM_i_o_State == the_lo_limit )
                    {
                        ++tries;
                    }

                }
                while( (timer >= 0) && (tries < 3) );


                if( the_lo_limit != LJM_i_o_State )
                {
                    result_number( -1 );
                }
                else
                {
                    result_number( LJM_i_o_State );
                }

                break;

        /****************************************************************************************************************************************************************
        *
        *   WAIT UNTIL OPERATOR CLOSES/OPENS SWITCH ON SB UNITS
        *   CIO0    16
        *   CIO1    17
        *   CIO2    18
        *   CIO3    19
        *
        ***************************************************************************************************************************************************************/
        case    10214:
                test_command( the_c_test_name_string );
                speak_string(the_c_test_name_string);

            //open_lab_jacks();

                measurement = 0;
                timer = 10;    // 30;
                timed_out = NO;
                tries = 0;

                do
                {
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting for Switch %02.1f", timer );
                    test_name( string_99_buffer );

                    if (timer <= 0)
                    {
                        timed_out = YES;
                    }

                //measurement = eDI(HandleJIG(), 0, the_hi_limit, &i_o_State );

                    if (i_o_State == the_lo_limit)
                    {
                        ++tries;
                    }

                }
                while ((timer >= 0) && (tries < 3));

            //close_lab_jacks();


                if (the_lo_limit != i_o_State)
                {
                    result_number(-1);
                }
                else
                {
                    result_number(i_o_State);
                }

                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - GO THRU JIG SWITCHS 3-12 CHECKING THAT WHILE ONE SWITCH IS ON, THAT THE OTHERS ARE OFF AND NOT SHORTED TO AN ON STATE. BCDI or -BC D12
        *
        ***************************************************************************************************************************************************************/
        case    10299:
                test_command( the_c_test_name_string );

                for( x = 1; x <= 12; ++x )
                    switch_result[x] = -1;

                timer = 9;
                tries = 0;
                open_gateway_serial_port();
                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                sprintf(message_99_buffer, "Switch JIG switch %d ON", (uint8_t)the_hi_limit );
                speak_string(message_99_buffer);

                do // WAIT FOR LO LIMIT SWITCH NUMBER PASSED IN FROM TEST LIMITS TO TURN ON
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)the_hi_limit );
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( message_99_buffer, "Waiting For BI%d ON %02.1f", (uint8_t)the_hi_limit, timer );
                    test_name( message_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==1))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                for( x = 1; x <= 12; ++x )
                {
                    timer = 9;
                    tries = 0;
                    switch_result[(int)the_hi_limit] = 0;

                    do  // CHECK OTHERS TO BE OFF
                    {
                        if( (uint8_t)the_hi_limit != (uint8_t)x )
                        {
                            // DON'T CHECK CURRENT SWITCH BUT THE REST
                            transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                            sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)x );
                            transmit_spaced_message(string_99_buffer);
                            serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                            usleep(100000);   // 100 ms
                            timer -= 0.100;
                            sprintf( message_99_buffer, "Checking Remainding BI's OFF %02.1f", timer );
                            test_name( message_99_buffer );

                            if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==0))
                            {
                                ++tries;
                                switch_result[x] = 0;
                            }
                        }
                        else
                        {
                            tries = 3;  // DON'T CHECK CURRENT SWITCH
                        }

                    }
                    while( (timer >= 0) && !check_for_abort() && (tries<3));
                    // CHECK FOR TIMER TIME OUT AND SET FLAG TO BREAK
                }

                for(y = 1; y <=12; ++y )
                {
                    if(switch_result[y] == -1 )
                    {
                        measurement = -1;
                        break;
                    }
                }

                if( measurement == -1 )
                {
                    close_gateway_serial_port();
                    result_number(measurement);
                    break;
                }

                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                sprintf(message_99_buffer, "Switch JIG switch %d OFF", (uint8_t)the_hi_limit );
                speak_string(message_99_buffer);

                timer = 9;
                tries = 0;

                do  // WAIT FOR OFF
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)the_hi_limit );
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( message_99_buffer, "Waiting For BI%d %02.1f", (uint8_t)the_hi_limit, timer );
                    test_name( message_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==0))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                if((uint8_t)char_response_buffer[22] != 0 )
                {
                    measurement = -1;
                }
                else
                {
                    measurement = (uint8_t)char_response_buffer[22];
                }

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - GO THRU JIG SWITCHS 3-12 CHECKING THAT WHILE ONE SWITCH IS ON, THAT THE OTHERS ARE OFF AND NOT SHORTED TO AN ON STATE.
        *
        ***************************************************************************************************************************************************************/
        case    10300:

                test_command( the_c_test_name_string );

                for( x = 3; x <= 12; ++x )
                    switch_result[x] = -1;

                timer = 9;
                tries = 0;
                open_gateway_serial_port();
                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                sprintf(message_99_buffer, "Switch JIG switch %d ON", (uint8_t)the_hi_limit );
                speak_string(message_99_buffer);

                do // WAIT FOR LO LIMIT SWITCH NUMBER PASSED IN FROM TEST LIMITS TO TURN ON
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)the_hi_limit );
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( message_99_buffer, "Waiting For BI%d ON %02.1f", (uint8_t)the_hi_limit, timer );
                    test_name( message_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==1))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                for( x = 3; x <= 12; ++x )
                {
                    timer = 9;
                    tries = 0;
                    switch_result[(int)the_hi_limit] = 0;

                    do  // CHECK OTHERS TO BE OFF
                    {
                        if( (uint8_t)the_hi_limit != (uint8_t)x )
                        {
                            // DON'T CHECK CURRENT SWITCH BUT THE REST
                            transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                            sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)x );
                            transmit_spaced_message(string_99_buffer);
                            serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                            usleep(100000);   // 100 ms
                            timer -= 0.100;
                            sprintf( message_99_buffer, "Checking Remaining BI's OFF %02.1f", timer );
                            test_name( message_99_buffer );

                            if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==0))
                            {
                                ++tries;
                                switch_result[x] = 0;
                            }
                        }
                        else
                        {
                            tries = 3;  // DON'T CHECK CURRENT SWITCH
                        }

                    }
                    while( (timer >= 0) && !check_for_abort() && (tries<3));
                    // CHECK FOR TIMER TIME OUT AND SET FLAG TO BREAK
                }

                for(y = 3; y <=12; ++y )
                {
                    if(switch_result[y] == -1 )
                    {
                        measurement = -1;
                        break;
                    }
                }

                if( measurement == -1 )
                {
                    close_gateway_serial_port();
                    result_number(measurement);
                    break;
                }

                memset(char_response_buffer,'\0',99);
                memset(string_99_buffer,'\0',99);

                sprintf(message_99_buffer, "Switch JIG switch %d OFF", (uint8_t)the_hi_limit );
                speak_string(message_99_buffer);

                timer = 9;
                tries = 0;

                do  // WAIT FOR OFF
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)the_hi_limit );
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( message_99_buffer, "Waiting For BI%d %02.1f", (uint8_t)the_hi_limit, timer );
                    test_name( message_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==0))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                if((uint8_t)char_response_buffer[22] != 0 )
                {
                    measurement = -1;
                }
                else
                {
                    measurement = (uint8_t)char_response_buffer[22];
                }

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 1 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10301:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();
                memset(char_response_buffer,'\0',99);

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 01 19 55 3C 60");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );


                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 2 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10302:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 03 0C 0C 00 C0 00 02 19 55 5F 59");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 3 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10303:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 04 0C 0C 00 C0 00 03 19 55 61 EA");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 4 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10304:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 08 0C 0C 00 C0 00 04 19 55 4B 26");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /**************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 5 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10305:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 09 0C 0C 00 C0 00 05 19 55 6A 31");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 6 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10306:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 0A 0C 0C 00 C0 00 06 19 55 09 08");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 7 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10307:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 0D 0C 0C 00 C0 00 07 19 55 37 BB");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 8 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10308:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 0E 0C 0C 00 C0 00 08 19 55 F7 27");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 9 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10309:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 0F 0C 0C 00 C0 00 09 19 55 D6 30");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 10 INPUT STATE
        *
        ***************************************************************************************************************************************************************/
        case    10310:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 11 0C 0C 00 C0 00 0A 19 55 F3 FB");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 11 INPUT STATE
        *
        **************************************************************************************************************************************************************/
        case    10311:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 12 0C 0C 00 C0 00 0B 19 55 28 77");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR BINARY 12 INPUT STATE
        *
        **************************************************************************************************************************************************************/
        case    10312:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 13 0C 0C 00 C0 00 0C 19 55 D0 B6");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR APPLICATION SOFTWARE VERSION
        *
        **************************************************************************************************************************************************************/
        case    10316:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;

                open_gateway_serial_port();

                memset(char_response_buffer,'\0',sizeof(char_response_buffer));
                memset(app_sw_version_str,'\0',sizeof(app_sw_version_str));
                memset(string_99_buffer,'\0',sizeof(string_99_buffer));

                BACnet_Addr_Int = (uint16_t)strtol(BACnet_Address, NULL, 16);
                build_object_id(object_id, (uint16_t) DEVICE_OBJECT_TYPE_ID, (uint32_t)(FDI_DEVICE_ID + BACnet_Addr_Int));

                do
                {
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 9D 01 04 02 73 4A 0C 0C %02X %02X %02X %02X 19 0C 2F F6",
                        object_id[0], object_id[1], object_id[2], object_id[3]);

                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message(string_99_buffer);

                    serial_receive_bacnet_bytes(&char_response_buffer, &l_num_bytes);

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf(string_99_buffer, "Waiting For Response %02.1f", timer);
                    test_name(string_99_buffer);

                    if (((uint8_t)char_response_buffer[SERVICE_ACK_BYTE] == (uint8_t)0x06) &&
                        ((uint8_t)char_response_buffer[PD_OPENING_TAG_3_BYTE] == (uint8_t)0x3E))
                    {
                        cntr = 0;
                        tries++;

                        // Check if the embedded BACnet stack is inserting an extra NULL character at the beginning of the string
                        if ((uint8_t)char_response_buffer[23] == (uint8_t)0x00)
                        {
                            index = 24; //start index of application software version + 1 to ignore null.
                            char_response_buffer[PROPERTY_LENGTH_BYTE]--; //subtract one from the length
                        }
                        else
                        {
                            index = 23; //start index of application software version
                        }

                        // Copy the number of characters in the application software version
                        while (cntr < (uint8_t)char_response_buffer[PROPERTY_LENGTH_BYTE])
                        {
                            app_sw_version_str[cntr] = char_response_buffer[index+cntr];
                            cntr++;
                        }
                    }
                }
                while ((timer >= 0) && !check_for_abort() && tries < 6);

                close_gateway_serial_port();

                result_string(app_sw_version_str);

                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR FIRMWARE REVISION NUMBER
        *
        **************************************************************************************************************************************************************/
        case    10317:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;

                open_gateway_serial_port();
                memset(char_response_buffer,'\0',sizeof(char_response_buffer));
                memset(fw_revision_number_str,'\0',sizeof(fw_revision_number_str));
                memset(string_99_buffer,'\0',sizeof(string_99_buffer));

                BACnet_Addr_Int = (uint16_t)strtol(BACnet_Address, NULL, 16);
                build_object_id(object_id, (uint16_t) DEVICE_OBJECT_TYPE_ID, (uint32_t)(FDI_DEVICE_ID + BACnet_Addr_Int));

                do
                {
                    sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 9D 01 04 02 73 42 0C 0C %02X %02X %02X %02X 19 2C E7 A8",
                        object_id[0], object_id[1], object_id[2], object_id[3]);

                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes(&char_response_buffer, &l_num_bytes);

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf(string_99_buffer, "Waiting For Response %02.1f", timer);
                    test_name(string_99_buffer);

                    if (((uint8_t)char_response_buffer[SERVICE_ACK_BYTE] == (uint8_t)0x06) &&
                        ((uint8_t)char_response_buffer[PD_OPENING_TAG_3_BYTE] == (uint8_t)0x3E))
                    {
                        cntr = 0;
                        tries++;

                        /* Check if the embedded BACnet stack is inserting an extra NULL character at the beginning of the string. */
                        if ((uint8_t)char_response_buffer[23] == (uint8_t)0x00)
                        {
                            index = 24; //start index of firmware revision number + 1 character to ignore null.
                            char_response_buffer[PROPERTY_LENGTH_BYTE]--; //subtract one from the length
                        }
                        else
                        {
                            index = 23; //start index of firmware revision number
                        }

                        /* Copy the number of characters in the firmware revision number */
                        while (cntr < (uint8_t)char_response_buffer[PROPERTY_LENGTH_BYTE])
                        {
                            fw_revision_number_str[cntr] = char_response_buffer[index+cntr];
                            cntr++;
                        }
                    }
                }
                while ((timer >= 0) && !check_for_abort() && tries < 6);

                close_gateway_serial_port();

                result_string(fw_revision_number_str);

                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR ACC1 COUNT
        *
        **************************************************************************************************************************************************************/
        case    10321:
                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 1D 0C 0C 05 C0 00 01 19 55 FD 86");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For ACC1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    // 300
                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (the_lo_limit != 0) )
                    {
                        // big-endian format
                        b.bytes.b_1 = (uint8_t)char_response_buffer[22]; // 0x01
                        b.bytes.b_0 = (uint8_t)char_response_buffer[23]; // 0x2C;
                        measurement = (uint16_t)b.w;
                        //printf("%02X %02X %d\n", (uint16_t)char_response_buffer[22],(uint16_t)char_response_buffer[23],(uint16_t)measurement);
                    }
                    // 0
                    else if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (the_lo_limit == 0) )
                    {
                        // big-endian format PowerPC Processor
                        b.bytes.b_1 = 0;
                        b.bytes.b_0 = (uint8_t)char_response_buffer[22]; // 0x00;
                        //printf("%d\n", measurement);
                        measurement = (uint16_t)b.w;
                    }



                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((uint8_t)measurement>=(uint8_t)the_lo_limit) && ((uint8_t)measurement<=(uint8_t)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                close_gateway_serial_port();
                result_number(measurement);

                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - ASK FOR ACC2 COUNT
        *
        **************************************************************************************************************************************************************/
        case    10322:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 21 0C 0C 05 C0 00 02 19 55 1B 21");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For ACC2 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    // 300
                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (the_lo_limit != 0) )
                    {
                        b.bytes.b_1 = (uint8_t)char_response_buffer[22]; // 0x01
                        b.bytes.b_0 = (uint8_t)char_response_buffer[23]; // 0x2C;
                        measurement = (uint16_t)b.w;
                    }
                    // 0
                    else if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (the_lo_limit == 0) )
                    {
                        b.bytes.b_1 = 0;
                        b.bytes.b_0 = (uint8_t)char_response_buffer[22]; // 0x00;
                        measurement = (uint16_t)b.w;
                    }



                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((uint8_t)measurement>=(uint8_t)the_lo_limit) && ((uint8_t)measurement<=(uint8_t)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);

                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - WRITE 0 TO ACC1 AND ACC2
        *
        **************************************************************************************************************************************************************/
        case    10323:

                test_command( the_c_test_name_string );

                timer = 3;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For ACC'S ZERO %02.1f", timer );
                    test_name( string_99_buffer );


                    // WRITE 0 TO ACC1
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 11 E4 01 04 02 23 38 0F 0C 05 C0 00 01 19 55 3E 21 00 3F 3B 89");
                    // WRITE 0 TO ACC2
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 11 E4 01 04 02 23 44 0F 0C 05 C0 00 02 19 55 3E 21 00 3F A8 96");

                    ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                close_gateway_serial_port();
                result_number(0);

                break;

        /***************************************************************************************************************************************************************
        *
        *   BACnet - TURN ON RELAY FOR -BC
        *
        **************************************************************************************************************************************************************/
        case    10324:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 5;
                timed_out = NO;

                open_gateway_serial_port();
                //open_lab_jacks();
                i_o_State = 1;

                do
                {
                    transmit_spaced_message("55 FF 02 00 01 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 11 E4 01 04 02 23 46 0F 0C 01 00 00 01 19 55 3E 91 01 3F 2E 34");
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                    //measurement = eDI(HandleJIG(), 0, CIO2, &i_o_State );
                }
                while( (timer >= 0) && !check_for_abort() ); //&& (i_o_State == 0) );


                close_gateway_serial_port();
                //close_lab_jacks();
                result_number(i_o_State);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - TURN OFF RELAY FOR -BC
        *
        ***************************************************************************************************************************************************************/
        case    10326:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 5;
                timed_out = NO;

                open_gateway_serial_port();
                //open_lab_jacks();
                i_o_State = 0;

                do
                {
                    transmit_spaced_message("55 FF 02 00 01 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 11 E4 01 04 02 23 50 0F 0C 01 00 00 01 19 55 3E 91 00 3F C8 6A");
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                    //measurement = eDI(HandleJIG(), 0, CIO2, &i_o_State );
                }
                while( (timer >= 0) && !check_for_abort() ); //&& (i_o_State == 0) );&& (i_o_State == 1) );


                close_gateway_serial_port();
                //close_lab_jacks();
                result_number(i_o_State);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ ANALOG INPUT AI1
        *
        ***************************************************************************************************************************************************************/
        case    10327:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 E2 0C 0C 00 00 00 01 19 55 3C 65");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For AI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    // 255.0
                    if( (uint8_t)char_response_buffer[2] == (uint8_t)0x06 )
                    {
                        if(get_debug_mode())
                            printf( "Data %02X %02X %02X %02X\n", (uint8_t)char_response_buffer[22],(uint8_t)char_response_buffer[23],(uint8_t)char_response_buffer[24],(uint8_t)char_response_buffer[25] );

                        u.bytes.b_3 = (uint8_t)char_response_buffer[22];
                        u.bytes.b_2 = (uint8_t)char_response_buffer[23];
                        u.bytes.b_1 = (uint8_t)char_response_buffer[24];
                        u.bytes.b_0 = (uint8_t)char_response_buffer[25];
                        measurement = (float)u.fv;
                        u.fv = (float)measurement;
                    }


                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((float)measurement>=(float)the_lo_limit) && ((float)measurement<=(float)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ ANALOG INOUT AI2
        *
        ***************************************************************************************************************************************************************/
        case    10318:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 E2 0C 0C 00 00 00 02 19 55 3C 65");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For AI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    if( (uint8_t)char_response_buffer[2] == (uint8_t)0x06 )
                    {
                        if(get_debug_mode())
                            printf( "Data %02X %02X %02X %02X\n", (uint8_t)char_response_buffer[22],(uint8_t)char_response_buffer[23],(uint8_t)char_response_buffer[24],(uint8_t)char_response_buffer[25] );

                        u.bytes.b_3 = (uint8_t)char_response_buffer[22];
                        u.bytes.b_2 = (uint8_t)char_response_buffer[23];
                        u.bytes.b_1 = (uint8_t)char_response_buffer[24];
                        u.bytes.b_0 = (uint8_t)char_response_buffer[25];
                        measurement = (float)u.fv;
                        u.fv = (float)measurement;
                    }


                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((float)measurement>=(float)the_lo_limit) && ((float)measurement<=(float)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ ANALOG INOUT AI3
        *
        ***************************************************************************************************************************************************************/
        case    10319:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 E2 0C 0C 00 00 00 03 19 55 3C 65");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For AI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    if( (uint8_t)char_response_buffer[2] == (uint8_t)0x06 )
                    {
                        if(get_debug_mode())
                            printf( "Data %02X %02X %02X %02X\n", (uint8_t)char_response_buffer[22],(uint8_t)char_response_buffer[23],(uint8_t)char_response_buffer[24],(uint8_t)char_response_buffer[25] );

                        u.bytes.b_3 = (uint8_t)char_response_buffer[22];
                        u.bytes.b_2 = (uint8_t)char_response_buffer[23];
                        u.bytes.b_1 = (uint8_t)char_response_buffer[24];
                        u.bytes.b_0 = (uint8_t)char_response_buffer[25];
                        measurement = (float)u.fv;
                        u.fv = (float)measurement;
                    }


                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((float)measurement>=(float)the_lo_limit) && ((float)measurement<=(float)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ ANALOG INOUT AI4
        *
        ***************************************************************************************************************************************************************/
        case    10320:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 E2 0C 0C 00 00 00 04 19 55 3C 65");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For AI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    if( (uint8_t)char_response_buffer[2] == (uint8_t)0x06 )
                    {
                        if(get_debug_mode())
                            printf( "Data %02X %02X %02X %02X\n", (uint8_t)char_response_buffer[22],(uint8_t)char_response_buffer[23],(uint8_t)char_response_buffer[24],(uint8_t)char_response_buffer[25] );

                        u.bytes.b_3 = (uint8_t)char_response_buffer[22];
                        u.bytes.b_2 = (uint8_t)char_response_buffer[23];
                        u.bytes.b_1 = (uint8_t)char_response_buffer[24];
                        u.bytes.b_0 = (uint8_t)char_response_buffer[25];
                        measurement = (float)u.fv;
                        u.fv = (float)measurement;
                    }


                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && (((float)measurement>=(float)the_lo_limit) && ((float)measurement<=(float)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ DIGITAL INPUT BI1 -BC
        *
        ***************************************************************************************************************************************************************/
        case    10328:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 55 0C 0C 00 C0 00 01 19 55 D3 0B");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3)); // && ((uint8_t)char_response_buffer[2] != (uint8_t)0x06)

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ DIGITAL INPUT BI2 -BC -BCAI
        *
        ***************************************************************************************************************************************************************/
        case    10329:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 55 0C 0C 00 C0 00 02 19 55 FF D3");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI2 %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3)); // && ((uint8_t)char_response_buffer[2] != (uint8_t)0x06)

                measurement = (uint8_t)char_response_buffer[22];

                close_gateway_serial_port();
                result_number(measurement);
                break;


        /****************************************************************************************************************************************************************
        *
        *   BACnet - SET BAUD RATE FOR SERIAL COMMUNCATIOINS
        *
        ***************************************************************************************************************************************************************/
        case    10330:

                test_command( the_c_test_name_string );

                // BAUD RATE IS PASSED IN VIA LIMITS FILE
                global_baud = (int)the_lo_limit;

                measurement = open_gateway_serial_port();

                if(measurement == TRUE )
                {
                    measurement = (int)the_lo_limit;
                }
                else
                {
                    measurement = 0;
                }

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *   SEND OPERATOR COMMAND AND WAIT FOR START BUTTON TO BE PRESSED AND TIME OUT AFTER 30 SECONDS
        *   JIG I/O READ INPUT - HI LIMIT IS CHANNEL NUMBER TO READ
        *   CIO0    16
        *   CIO1    17
        *   CIO2    18
        *   CIO3    19
        *
        ***************************************************************************************************************************************************************/
        case    10332:
                test_command( the_c_test_name_string );
                speak_string(the_c_test_name_string);

                //open_lab_jacks();

                test_name( the_c_test_name_string );

                measurement = 0;  // TEST BUTTON INTERMITTIN
                timer = 75;
                tries = 0;
                back_off_state = 1;

                do
                {
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting for Start Button %02.1f", timer );
                    test_name( string_99_buffer );

                    //measurement = eDI(HandleJIG(), 0, CIO0, &i_o_State );

                    // NORMALLY PULLED HI UNTL START BUTTON PRESSED AND GOES LOW
                    if( (long)i_o_State == (long)0)
                    {
                        ++tries;
                    }

                }
                while( (timer >= 0) && (tries < 1) && !check_for_abort() );

                test_pause( 1, NO );

                do
                {
                    //dummy = eDI(HandleJIG(), 0, CIO0, &back_off_state );
                }
                while( back_off_state == 0 );

                //close_lab_jacks();

                if( the_lo_limit == i_o_State )
                {
                    result_number( i_o_State );
                }
                else
                {
                    result_number( -1 );
                }

                break;

        /****************************************************************************************************************************************************************
        *   CHANGE BACnet DESTINATION ADDRESS WHEN SENDNG MESSAGES
        *
        ***************************************************************************************************************************************************************/
        case    10334:
                test_command( the_c_test_name_string );

                test_name( the_c_test_name_string );

                strncpy(BACnet_Address,the_c_limit_string, 3);
                result_string( BACnet_Address );
                break;

        /****************************************************************************************************************************************************************
        *
        *
        *
        *   TEST ENDIAN NESS
        *
        *
        *
        ***************************************************************************************************************************************************************/
        case    10335:
                test_command( the_c_test_name_string );

                test_name( the_c_test_name_string );

                // 0x40 0x80 0x00 0x00

                u.bytes.b_3 = 0x40;
                u.bytes.b_2 = 0x80;
                u.bytes.b_1 = 0x00;
                u.bytes.b_0 = 0x00;
                measurement = (float)u.fv;
                u.fv = (float)measurement;
                result_number( measurement );
                break;

        /*******************************************************************************
        *
        *   BACnet - READ OVERRIDE STATUS - LIMIT SHOULD BE RESPONSE 00 NORMAL 0x20 OVERRIDDEN
        *
        ********************************************************************************/
        case    10337:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 01 00 00 01 19 6F B9 B1");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI2 %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[23]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[23];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - TURN ON/OFF RELAY FOR -44BC
        *
        ***************************************************************************************************************************************************************/
        case    10339:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 5;
                timed_out = NO;

                open_gateway_serial_port();

                do
                {
                    // TRANSMIT RELAY ON OR OFF
                    transmit_spaced_message("55 FF 02 00 01 00 00 7C");
                    sprintf( string_99_buffer, "55 FF 05 01 00 00 11 E4 01 04 02 23 46 0F 0C 01 00 00 %02X 19 55 3E 91 %02X 3F 2E 34", (uint8_t)the_hi_limit, (uint8_t)the_lo_limit );
                    transmit_spaced_message(string_99_buffer);

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %d %02.1f", (uint8_t)the_hi_limit,timer );
                    test_name( string_99_buffer );

                    // CHECK RELAY OBJECT STATUS
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf( string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 2D 0C 0C 01 00 00 %02X 19 55 8B D5", (uint8_t)the_hi_limit);
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;

                }
                while( (timer >= 0) && !check_for_abort() && (tries<3) );

                if( the_lo_limit == (uint8_t)char_response_buffer[22] )
                {
                    measurement = (uint8_t)char_response_buffer[22];
                }
                else
                {
                    measurement = -1;
                }


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - TURN ON/OFF RELAY FOR -44BC
        *
        ***************************************************************************************************************************************************************/
        case    10340:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 9;
                timed_out = NO;

                open_gateway_serial_port();

                do
                {
                    // TRANSMIT RELAY ON OR OFF
                    transmit_spaced_message("55 FF 02 00 01 00 00 7C");
                    sprintf( string_99_buffer, "55 FF 05 01 00 00 11 E4 01 04 02 23 46 0F 0C 01 00 00 %02X 19 55 3E 91 %02X 3F 2E 34", (uint8_t)the_hi_limit, (uint8_t)the_lo_limit );
                    transmit_spaced_message(string_99_buffer);

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %d %02.1f", (uint8_t)the_hi_limit,timer );
                    test_name( string_99_buffer );

                    // CHECK DIGITAL INPUT FEEDBACK FOR REALY
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf( string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 55 0C 0C 00 C0 00 %02X 19 55 D3 0B", (uint8_t)the_hi_limit);
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;

                }
                while( (timer >= 0) && !check_for_abort() && (tries<3) );

                if( the_lo_limit == (uint8_t)char_response_buffer[22] )
                {
                    measurement = (uint8_t)char_response_buffer[22];
                }
                else
                {
                    measurement = -1;
                }


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ DIGITAL INPUT hi_limit(BI to check) (expected result)lo_limit  -BC
        *
        ***************************************************************************************************************************************************************/
        case    10341:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    sprintf( string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 55 0C 0C 00 C0 00 %02X 19 55 D3 0B", (uint8_t)the_hi_limit);
                    transmit_spaced_message(string_99_buffer);
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI%d %02.1f", (uint8_t)the_hi_limit, timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[22];

                // CHECK REST TO BE OFF IF EXPECTED RESULT IS ON
                if((uint8_t)the_lo_limit != 0 )
                {
                    for( x = 1; x <= 4; ++x )
                        switch_result[x] = -1;

                    for( x = 1; x <= 4; ++x )
                    {
                        timer = 5;
                        tries = 0;
                        switch_result[(int)the_hi_limit] = 0;

                        do  // CHECK OTHERS TO BE OFF
                        {
                            if( (uint8_t)the_hi_limit != (uint8_t)x )
                            {
                                // DON'T CHECK CURRENT SWITCH BUT THE REST
                                transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                                sprintf(string_99_buffer, "55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 00 C0 00 %02X 19 55 3C 60", (uint8_t)x );
                                transmit_spaced_message(string_99_buffer);
                                serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                                usleep(100000);   // 100 ms
                                timer -= 0.100;
                                sprintf( message_99_buffer, "Checking Remainding BI's OFF %02.1f", timer );
                                test_name( message_99_buffer );

                                if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[22]==0))
                                {
                                    ++tries;
                                }
                            }
                            else
                            {
                                tries = 5;  // DON'T CHECK CURRENT SWITCH
                            }

                        }
                        while( (timer >= 0) && !check_for_abort() && (tries<5));

                        if( (uint8_t)char_response_buffer[22]==0 )
                        {
                            switch_result[x] = 0;
                        }
                    }
                }

                // CHECK REST TO BE OFF IF EXPECTED RESULT IS ON
                if((uint8_t)the_lo_limit != 0 )
                    for(y = 1; y <=4; ++y )
                    {
                        if(switch_result[y] == -1 )
                        {
                            measurement = -1;
                            break;
                        }
                    }

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   MODBUS - TURN ON RELAY FOR -MBAI
        *
        ***************************************************************************************************************************************************************/
        case    10524:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 5;
                timed_out = NO;

                open_gateway_serial_port();
                //open_lab_jacks();
                i_o_State = 1;

                do
                {
                    transmit_spaced_message_modbus("01 05 00 00 FF 00 8C 3A");
                    //MPWaitOnSemaphore( sem_id_delay, 100 * kDurationMillisecond );
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                    //measurement = eDI(HandleJIG(), 0, CIO2, &i_o_State );
                }
                while( (timer >= 0) && !check_for_abort() && (i_o_State == 0) );

                //close_lab_jacks();

                close_gateway_serial_port();
                result_number(i_o_State);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - TURN OFF RELAY FOR -BC
        *
        ***************************************************************************************************************************************************************/
        case    10526:

                test_command( the_c_test_name_string );

                measurement = 0;
                timer = 5;
                timed_out = NO;

                open_gateway_serial_port();
                //open_lab_jacks();
                i_o_State = 0;

                do
                {
                    transmit_spaced_message_modbus("01 05 00 00 00 00 CD CA");
                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For Relay %02.1f", timer );
                    test_name( string_99_buffer );

                    if( timer <= 0 )
                    {
                        timed_out = YES;
                    }

                    //measurement = eDI(HandleJIG(), 0, CIO2, &i_o_State );
                }
                while( (timer >= 0) && !check_for_abort() && (i_o_State == 1) );

                //close_lab_jacks();

                close_gateway_serial_port();
                result_number(i_o_State);
                break;

        /****************************************************************************************************************************************************************
        *
        *   MODBUS - READ DIGITAL INPUT BI1 -MBAI
        *
        ***************************************************************************************************************************************************************/
        case    10528:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message_modbus("01 02 00 00 00 01 B9 CA");
                    serial_receive_modbus( &char_response_buffer );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[1] == (uint8_t)0x02) && ((uint8_t)char_response_buffer[3]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3)); // && ((uint8_t)char_response_buffer[2] != (uint8_t)0x06)

                measurement = (uint8_t)char_response_buffer[3];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   MODBUS - READ DIGITAL INPUT BI2 -MBAI
        *
        ***************************************************************************************************************************************************************/
        case    10529:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message_modbus("01 02 00 01 00 01 B9 CA");
                    serial_receive_modbus( &char_response_buffer );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For BI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[1] == (uint8_t)0x02) && ((uint8_t)char_response_buffer[3]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3)); // && ((uint8_t)char_response_buffer[2] != (uint8_t)0x06)

                measurement = (uint8_t)char_response_buffer[3];

                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ ANALOG INPUT AI1 -MBAI
        *
        ***************************************************************************************************************************************************************/
        case    10527:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message_modbus("01 04 00 00 00 01 31 CA");
                    serial_receive_modbus( &char_response_buffer );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For AI1 %02.1f", timer );
                    test_name( string_99_buffer );

                    measurement = -1;

                    // 255.0
                    if( (uint8_t)char_response_buffer[1] == (uint8_t)0x04 )
                    {
                        if(get_debug_mode())
                            printf( "Data %02X %02X\n", (uint8_t)char_response_buffer[3],(uint8_t)char_response_buffer[4] );

                        b.bytes.b_0 = (uint8_t)char_response_buffer[4]; //
                        b.bytes.b_1 = (uint8_t)char_response_buffer[3]; //
                        measurement = (uint16_t)b.w;
                        b.w = (uint16_t)measurement;
                    }


                    if( ((uint8_t)char_response_buffer[1] == (uint8_t)0x04) && (((float)measurement>=(float)the_lo_limit) && ((float)measurement<=(float)the_hi_limit))  )
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));


                close_gateway_serial_port();
                result_number(measurement);
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ OVERRIDE STATUS #RELAY 1 - LIMIT SHOULD BE RESPONSE 00 NORMAL 0x20 OVERRIDDEN 44BC
        *
        ***************************************************************************************************************************************************************/
        case    10531:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");                // 01
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 01 00 00 01 19 6F B9 B1");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For OVD 1 Status %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[23]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[23];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ OVERRIDE STATUS #RELAY 2 - LIMIT SHOULD BE RESPONSE 00 NORMAL 0x20 OVERRIDDEN 44BC
        *
        ***************************************************************************************************************************************************************/
        case    10532:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");                         // 02
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 01 00 00 02 19 6F B9 B1");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For OVD 2 Statis %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[23]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[23];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ OVERRIDE STATUS #RELAY 3 - LIMIT SHOULD BE RESPONSE 00 NORMAL 0x20 OVERRIDDEN 44BC
        *
        ***************************************************************************************************************************************************************/
        case    10533:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");                         // 03
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 01 00 00 03 19 6F B9 B1");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For OVD 3 Statis %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[23]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[23];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - READ OVERRIDE STATUS #RELAY 4 - LIMIT SHOULD BE RESPONSE 00 NORMAL 0x20 OVERRIDDEN 44BC
        *
        ***************************************************************************************************************************************************************/
        case    10534:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");                         // 04
                    transmit_spaced_message("55 FF 05 01 00 00 0D 11 01 04 02 23 00 0C 0C 01 00 00 04 19 6F B9 B1");
                    serial_receive_bacnet_bytes( &char_response_buffer, &l_num_bytes );

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For OVD 4 Statis %02.1f", timer );
                    test_name( string_99_buffer );

                    if( ((uint8_t)char_response_buffer[2] == (uint8_t)0x06) && ((uint8_t)char_response_buffer[23]==the_lo_limit))
                        ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)char_response_buffer[23];

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - BCAO Analog out 100%
        *
        ***************************************************************************************************************************************************************/
        case    10536:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 14 E7 01 04 02 23 37 0F 0C 00 40 00 01 19 55 3E 44 42 C8 00 00 3F AC C0");

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For 100% Analog Out %%02.1f", timer );
                    test_name( string_99_buffer );

                    ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)100;

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   ACnet - BCAO Analog out 50%
        *
        ***************************************************************************************************************************************************************/
        case    10537:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 14 E7 01 04 02 23 38 0F 0C 00 40 00 01 19 55 3E 44 42 48 00 00 3F 45 0F");

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For 50% Analog Out %%02.1f", timer );
                    test_name( string_99_buffer );

                    ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)50;

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BACnet - BCAO Analog out 0%
        *
        ***************************************************************************************************************************************************************/
        case    10538:

                test_command( the_c_test_name_string );

                timer = 9;
                tries = 0;
                open_gateway_serial_port();

                do
                {
                    transmit_spaced_message("55 FF 02 01 00 00 00 7C");
                    transmit_spaced_message("55 FF 05 01 00 00 14 E7 01 04 02 23 39 0F 0C 00 40 00 01 19 55 3E 44 00 00 00 00 3F 90 A5");

                    usleep(100000);   // 100 ms
                    timer -= 0.100;
                    sprintf( string_99_buffer, "Waiting For 0% Analog Out %%02.1f", timer );
                    test_name( string_99_buffer );

                    ++tries;
                }
                while( (timer >= 0) && !check_for_abort() && (tries<3));

                measurement = (uint8_t)0;

                result_number(measurement);
                close_gateway_serial_port();
                break;

        /****************************************************************************************************************************************************************
        *
        *   BK METER READ DC VOLTAGE
        *
        ***************************************************************************************************************************************************************/
        case    10600:

                test_command( the_c_test_name_string );
                measurement = dcv_measure_BK5491();
                usleep(100000);   // 100 ms
                timer -= 0.100;
                sprintf( string_99_buffer, "Waiting For DMM DC Measurement %02.1f", timer );
                test_name( string_99_buffer );
                result_number(measurement);

                break;

        /****************************************************************************************************************************************************************
        *
        *   BK METER INITIALIZE
        *
        ***************************************************************************************************************************************************************/
        case    10601:

                test_command( the_c_test_name_string );

                measurement = (int)init_BK5491();

                test_name( string_99_buffer );

                result_number(measurement);

                break;

        /****************************************************************************************************************************************************************
        *
        *   BK METER READ DIODE
        *
        ***************************************************************************************************************************************************************/
        case    10602:

                test_command( the_c_test_name_string );
                measurement = 0;
                measurement = diode_measure_BK5491();

                test_name( "Diode Measuremente" );

                result_number(measurement);

                break;

        /****************************************************************************************************************************************************************
        *
        *   BK METER READ AC VOLTAGE
        *
        ***************************************************************************************************************************************************************/
        case    10604:

                test_command( the_c_test_name_string );
                measurement = acv_measure_BK5491();
                usleep(100000);   // 100 ms
                timer -= 0.100;
                sprintf( string_99_buffer, "Waiting For DMM AC Measurement %02.1f", timer );
                test_name( string_99_buffer );
                result_number(measurement);

                break;



            default:
                sprintf( the_c_limit_string, "Test %d Not Listed", (int)the_test_number);
                test_command(the_c_limit_string);
                test_name(the_c_limit_string);
                break;
    }

}

void test_pause( double pause_time, bool update_view )
{
    bool    stop_testing = NO;
    char    string[33];

    while( ( (double)pause_time > (double)0 )  && ( stop_testing == NO ) )
    {
        stop_testing = check_for_abort();

        sprintf( string, "Pausing %02.1f", pause_time );

        if( update_view == YES )
        {
            test_name( string );
        }

        usleep(100000);   // 100 ms

        pause_time -= 0.1;

        g_thread_yield ();
    }
}

void build_object_id(uint8_t * object_id, uint16_t object_type, uint32_t object_instance)
{
    object_id[0] =  ((object_type & 0x3FF) >> 2);
    object_id[1] = (((object_type & 0x03) << 6) + ((object_instance & 0x3F0000) >> 16));
    object_id[2] =  ((object_instance & 0xFF00) >> 8);
    object_id[3] =   (object_instance & 0xFF);
}


