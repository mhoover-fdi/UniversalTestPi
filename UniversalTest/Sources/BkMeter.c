#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <unistd.h>

#include <sys/file.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

#include "../headers/TestModel.h"
#include "../headers/SerialModel.h"
#include "../headers/TestStandard.h"
#include "../headers/BkMeter.h"

#define	BUFFER_SIZE	1024
#define BK5491_PORT "/dev/ttyUSB1"

struct termios the_termios_struct;
struct termios original_termios_struct;

int		    BK5491_gateway = -1;
static int  error = 0;

double	    dmm_measurement;


static char	last_sent_message[ 99 ];

int open_BK5491_serial_port( void )
{
    if( BK5491_gateway == 0 )
	{
		return NO;
	}

	BK5491_gateway = open( BK5491_PORT, O_RDWR | O_NONBLOCK | O_NOCTTY ); // O_APPEND
    //BK5491_gateway = OpenComConfig(4, "COM4", 9600, 0, 8, 1, 0, 0);


	if( BK5491_gateway == 0 )
	{
		return BK5491_gateway;
	}

	// get current options so can restore later
	error = tcgetattr( BK5491_gateway, &the_termios_struct );

	cfmakeraw( &the_termios_struct );

	the_termios_struct.c_ispeed = B9600;
	the_termios_struct.c_ospeed = B9600;

	//the_termios_struct.c_cflag |= CS8 | CCTS_OFLOW | CRTS_IFLOW | CREAD | CLOCAL;
    the_termios_struct.c_cflag &= ~PARENB;
    the_termios_struct.c_cflag &= ~CSTOPB;
    the_termios_struct.c_cflag &= ~CSIZE;
    the_termios_struct.c_cflag |= CS8;

	error = tcsetattr( BK5491_gateway, TCSANOW, &the_termios_struct );


	error = fcntl( BK5491_gateway, F_SETFL, O_NONBLOCK ); // O_FSYNC ); // FNDELAY);

	error = tcflush( BK5491_gateway, TCIOFLUSH );  // clear contents of serial buffers

	error = tcflush( BK5491_gateway, TCIFLUSH );  // clear contents of serial buffers

    if( (int)BK5491_gateway < (int)0 )
	{
        test_command("Serial Port Open Error");
        speak_string("Serial Port Open Error");
        sleep(3);
		return FALSE;
	}

	return BK5491_gateway;
}

double dcv_measure_BK5491( void )
{
	char    char_99_RECEIVE_message[ 99 ];
	long    l_num_bytes = 0;;
    char    *end;
	double	measurement;

    open_BK5491_serial_port();


    l_num_bytes = 22;
    BK5491_send( ":FUNC VOLT:DC;:FETC?\r\n", &l_num_bytes  ); // ;:read?
    memset( char_99_RECEIVE_message, 0, 98 );
    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

	measurement = strtod(char_99_RECEIVE_message, &end);

	return measurement;
}

double acv_measure_BK5491( void )
{
	char    char_99_RECEIVE_message[ 99 ];
	long    l_num_bytes = 0;;
    char    *end;
	double	measurement;

    open_BK5491_serial_port();


    l_num_bytes = 22;
    BK5491_send( ":FUNC VOLT:AC;:FETC?\r\n", &l_num_bytes  ); // ;:read?
    memset( char_99_RECEIVE_message, 0, 98 );
    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

	measurement = strtod(char_99_RECEIVE_message, &end);

	return measurement;
}


double diode_measure_BK5491( void )
{
	char    char_99_RECEIVE_message[ 99 ];
	long    l_num_bytes = 0;;
    char    *end;
	double	measurement;

    open_BK5491_serial_port();

    l_num_bytes = 27;
    BK5491_send( ":FUNC DIOD;:TRIG:SOUR IMM\r\n", &l_num_bytes  );
    memset( char_99_RECEIVE_message, 0, 98 );
    BK5491_receive( char_99_RECEIVE_message );

    l_num_bytes = 8;
    BK5491_send( ":FETC?\r\n", &l_num_bytes  );
    memset( char_99_RECEIVE_message, 0, 98 );
    BK5491_receive( char_99_RECEIVE_message );


    memmove( &char_99_RECEIVE_message[0], &char_99_RECEIVE_message[6], strlen(char_99_RECEIVE_message) );

    close_BK5491_serial_port();

	measurement = strtod(char_99_RECEIVE_message, &end);

    return measurement;
}


void close_BK5491_serial_port( void )
{
	if( BK5491_gateway )
	{
		//close( BK5491_gateway );
        //status = CloseCom(4);
		BK5491_gateway = -1;
	}

}


int init_BK5491( void )
{
    long    l_num_bytes;
    int     wrote = 0;

    open_BK5491_serial_port();

    test_command("Initializing BK Voltmeter...");
	//tcflush( BK5491_gateway, TCIFLUSH );  // clear contents of serial buffers

    l_num_bytes = 5;
    wrote = BK5491_send( "*RST\n",&l_num_bytes ); // ISSUE RESET COMMAND TO BK PRECISION VOLT METER


    close_BK5491_serial_port();

    if(wrote == 5)
    {
        return 1;
    }
    else
    {
        return -1;
    }


}


int BK5491_send( char *char_ptr_original_message, long *l_message_length  )
{
	long			the_message_length = *l_message_length;
	int				wrote = 0;
	extern int		BK5491_gateway;

    memset( last_sent_message, '\0', 99 );
    memmove( last_sent_message, char_ptr_original_message, the_message_length);

    wrote = write( BK5491_gateway, char_ptr_original_message, the_message_length );
    //wrote = ComWrt(4, char_ptr_original_message, the_message_length);


    return wrote;
}


// RETURNED ASCII DATA IS TERMINATED VIA ASCII CODE 10, OR NEW LINE "\n"
void BK5491_receive( char *serial_receive_buffer )
{
	char			char_99_buffer[ 99 ];
	char			*return_char;
	char			char_1_buffer[ 1 ];
	bool			b_complete_message = NO;
	long			x = 0;
	//MPSemaphoreID   sem_id_delay;
	int             timer = 0;

    // CREATE A BINARY SEMAPHORE
	//MPCreateSemaphore( 1, 0, &sem_id_delay );

	memset( char_99_buffer, '\0', 99 );

	x = 0;
	b_complete_message = FALSE;

    while(( b_complete_message == NO ) && ( timer < 3000 ))
    {
        // TIME OUT AFTER 1 SECOND
        while( ( b_complete_message == NO ) && ( timer < 3000 ) )
        {
            //MPWaitOnSemaphore( sem_id_delay, 1 * kDurationMillisecond );
            sleep(.001);
            ++timer;

            //if( ComRd(4, char_1_buffer, 1) >= 1 )
            if( read( BK5491_gateway, char_1_buffer, 1 ) >= 1 )
            {
                memmove( &serial_receive_buffer[ x ], &char_1_buffer[ 0 ], 1 );

                // METER TERMINATES DATA WITH RETURN FEED WITH THIS COMMAND QUERY
                if( strcmp( last_sent_message, "FUNC?\r\n" ) == 0 )
                {
                    // END OF MESSAGE FROM BKMETER
                    if( '\r' == (uint8_t)serial_receive_buffer[ x ] )
                    {
                        b_complete_message = YES;
                    }
                    else
                        ++x;
                }
                else
                {

                    // END OF MESSAGE FROM BKMETER
                    if( '\n' == (uint8_t)serial_receive_buffer[ x ] )
                    {
                        b_complete_message = YES;
                    }
                    else
                        ++x;
                }
            }
            //MPYield();
        }
    }

    // CHECK FOR RECEIVE TIME OUT
    if( timer >= 9000 )
    {
        test_command("BK 5491B ERROR");
        test_name("Timed Out Waiting For Voltmeter");
    }

	// :FUNC VOLT:DC;:FETC?\r\n
    if( (strcmp( last_sent_message, "FUNC?\r\n" ) == 0) || strcmp( last_sent_message, ":FUNC VOLT:DC;:FETC?\r\n" ) == 0 )
    {
        // REMOVE RETURN CHAR FROM METER
        return_char = strstr(serial_receive_buffer, "\r" );
        memcpy( serial_receive_buffer, return_char + 1, strlen(serial_receive_buffer));
        memcpy( char_99_buffer, serial_receive_buffer, strlen(serial_receive_buffer));
        memcpy( serial_receive_buffer, char_99_buffer, strlen(serial_receive_buffer));
    }
}

void measure_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 7;
    BK5491_send( "FETC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

//    SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void dcv_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long    l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 15;
    BK5491_send( ":FUNC VOLT:DC\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

 //   SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void acv_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long    l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 15;
    BK5491_send( ":FUNC VOLT:AC\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

//    SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void res_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 11;
    BK5491_send( ":FUNC RES\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

 //   SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void freq_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 12;
    BK5491_send( ":FUNC FREQ\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

 //   SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void diode_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 12;
    BK5491_send( ":FUNC DIOD\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

 //   SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}

void cont_BK5491(void)
{
    char    char_99_RECEIVE_message[ 99 ];
    long l_num_bytes;

    open_BK5491_serial_port();

    l_num_bytes = 12;
    BK5491_send( ":FUNC CONT\r\n", &l_num_bytes  );

    l_num_bytes = 7;
    BK5491_send( "FUNC?\r\n", &l_num_bytes  );

    memset( char_99_RECEIVE_message, 0, 98 );

    BK5491_receive( char_99_RECEIVE_message );

    close_BK5491_serial_port();

 //   SetCtrlVal(get_dmm_win(), DMM_PANEL_MEASUREMENT_STRING, char_99_RECEIVE_message);
}


