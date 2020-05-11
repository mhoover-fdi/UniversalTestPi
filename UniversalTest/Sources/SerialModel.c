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


/*****************************************************************
*
*   Description     - Defines
*
*****************************************************************/
#define	BUFFER_SIZE	1024
//#define	GATEWAY	"/dev/cu.USA19QW1913P1.1"
// #define	GATEWAY	"/dev/cu.usbserial-BBOPYNPP"   // BACnet RS485 USOPTL4 USB Adapter usbserial-BBUF295B : cu.usbserial-BBUF295B
#define GATEWAY "/dev/ttyUSB0"

/*****************************************************************
*
*   Description     - GLOBALS
*
*****************************************************************/
int     global_baud = 9600;
char    BACnet_Address[3] = {0,0,0};

char	the_buff [ BUFFER_SIZE ];
char	the_buff2[ BUFFER_SIZE ];

struct	termios	the_termios_struct;
struct	termios	originl_termios_struct;

int     message_num = 0;
int		gateway = 0;


char    char_1024_debug_raw[1024];
char    expected_response_buffer[99];
char    expected_message_buffer[99];
bool    found_message_notification = NO;
char	last_spaced_message[ 99 ];

char    char_99_monitor_message[ 99 ];
char    char_99_master_message[ 99 ];

char    char_99_raw_bytes_debug[ 99 ];
uint8_t mstp_address = 0;
uint8_t token_passing = YES;


//static int status = 0;

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
bool open_gateway_serial_port( void )
{
	if( gateway != 0 )
	{
		return NO;
	}

	gateway = open( GATEWAY, O_RDWR | O_NONBLOCK | O_NOCTTY ); // O_APPEND

	if( gateway < 0 )
	{
        test_command("Serial Port Open Error");
        speak_string("Serial Port Open Error");
		sleep(3);
		return false;
	}

	// get current options so can restore later
	tcgetattr( gateway, &the_termios_struct );

	cfmakeraw( &the_termios_struct );

    //the_termios_struct.c_ispeed = B38400; //global_baud;   // B9600 B57600
    //the_termios_struct.c_ospeed = B38400; //global_baud;

    if(global_baud == 38400)
    {
        cfsetspeed(&the_termios_struct,B38400); // PI
    }
    if(global_baud == 115200)
    {
        cfsetspeed(&the_termios_struct,B115200); // PI
    }
//	the_termios_struct.c_cflag |= CS8 | CCTS_OFLOW | CRTS_IFLOW | CREAD | CLOCAL;

//	the_termios_struct.c_cflag |= CS8 | TCOON | TCION | CREAD | CLOCAL;

 	// No parity (8N1):
 	the_termios_struct.c_cflag &= ~CSIZE;   // PI & bitmask with current value to zero
 	the_termios_struct.c_cflag &= ~CSTOPB;  // PI enable stop bit
    the_termios_struct.c_cflag &= ~PARENB;  // PI disable parity bit
    the_termios_struct.c_cflag |= CS8;      // PI 8 data bits
    the_termios_struct.c_cflag |= CLOCAL;   // PI Local line - do not change "owner" of port
    the_termios_struct.c_cflag |= CREAD;    // PI Enable receiver

   //the_termios_struct.c_cflag &= ~PARENB;
    //the_termios_struct.c_cflag &= ~CSTOPB;
    //the_termios_struct.c_cflag &= ~CSIZE;
    //the_termios_struct.c_cflag |= CS8;

	tcsetattr( gateway, TCSANOW, &the_termios_struct );

	fcntl( gateway, F_SETFL, O_NONBLOCK ); // O_FSYNC ); // FNDELAY);

	tcflush( gateway, TCIOFLUSH );  // clear contents of serial buffers

	return TRUE;
}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void close_gateway_serial_port( void )
{
    if( gateway )
	{
        //status = CloseCom(3);

        //status = viUnlock(gateway);
        //status = viClose(gateway);
        //status = viClose(gatewayRM);
        gateway = 0;
    }
}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
int t_read( int gateway, char *out_buffer, int bytes )
{
    int read_bytes = 0;

//    MPEnterCriticalRegion( the_critical_region_id, kDurationForever );

    read_bytes = read( gateway, out_buffer, 1 );
    //status = viRead(gatewayRM, (unsigned char *)out_buffer, 1, retCount);
    //ComRd(3, out_buffer, 1);

//    MPExitCriticalRegion( the_critical_region_id );

    return read_bytes;
}


/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void init_gateway( void )
{
	test_command("Reseting BACnet Gateway...");
	tcflush( gateway, TCIFLUSH );  // clear contents of serial buffers
}


/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void transmit_un_spaced_message( char *char_ptr_original_message )
{
	char			char_99_encoded_message_buffer[ 99 ];
	char 			char_99_raw_message_buffer[ 99 ];
	char			char_99_original_message[ 99 ];
	long			l_num_bytes;

	test_name( char_ptr_original_message );

    memset( char_99_original_message, '\0', 99 );
	memmove( &char_99_original_message[ 0 ], &char_ptr_original_message[0], 99 );

	l_num_bytes = strlen(char_99_original_message) / 2;

    convert_c_string_to_raw_message( &l_num_bytes, char_99_original_message, char_99_raw_message_buffer );
	encode_message( &l_num_bytes, char_99_raw_message_buffer, char_99_encoded_message_buffer );

	transmit_data( char_99_encoded_message_buffer, &l_num_bytes );
}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void transmit_spaced_message( char *char_ptr_original_message )
{
	char			char_99_encoded_message_buffer[ 99 ];
	char 			char_99_raw_message_buffer[ 99 ];
	char			char_99_original_message[ 99 ];
	long			l_num_bytes = 0;
	char            *end;
    uint8_t         address = 0;
    size_t          size = 0;

    size = strlen(char_ptr_original_message) + 1;

    memset( char_99_original_message, '\0', 99 );
	memmove( &char_99_original_message[0], &char_ptr_original_message[0], size);
	memmove( &last_spaced_message[ 0 ], &char_ptr_original_message[0], size );

    remove_spaces_and_count_bytes( char_99_original_message, &l_num_bytes );
	convert_c_string_to_raw_message( &l_num_bytes, char_99_original_message, char_99_raw_message_buffer );

    // PLACE ADDRESS BEFORE CALCULATE HEADER CRC
    if( (BACnet_Address[0] != 0) && (BACnet_Address[1] != 0) )
    {
        address = (uint8_t)strtoul(BACnet_Address, &end,16);
        char_99_raw_message_buffer[3] = address;
    }

    encode_message( &l_num_bytes, char_99_raw_message_buffer, char_99_encoded_message_buffer );

	transmit_data( char_99_encoded_message_buffer, &l_num_bytes );

}
/***************************************************************
*
*   Description     * Function
*
****************************************************************/

#define NUMDATA 6
uint8_t modbus_address_hex = 0;
void transmit_spaced_message_modbus( char *char_ptr_original_message )
{
	char 			char_99_raw_message_buffer[ 99 ];
	char			char_99_original_message[ 99 ];
	long			l_num_bytes = 0;
	char            *end;
	unsigned char   Crc_HByte,Crc_LByte;	//
	unsigned int    Crc; //....
    int i = 0;

    memset( char_99_original_message, '\0', 99 );
    memset( char_99_raw_message_buffer, '\0', 99 );
	memmove( &char_99_original_message[ 0 ], &char_ptr_original_message[0], 99 );
	memmove( &last_spaced_message[ 0 ], &char_ptr_original_message[0], 99 );

    remove_spaces_and_count_bytes( char_99_original_message, &l_num_bytes );
	convert_c_string_to_raw_message( &l_num_bytes, char_99_original_message, char_99_raw_message_buffer );

    // PLACE ADDRESS BEFORE CALCULATE HEADER CRC
 //   if( (BACnet_Address[0] != 0) && (BACnet_Address[1] != 0) )
    {
        modbus_address_hex = (uint8_t)strtoul(BACnet_Address, &end,16);
        char_99_raw_message_buffer[0] = modbus_address_hex;
    }

 	Crc=0xFFFF;
	for (i=0; i<NUMDATA; i++)
	{
		Crc = CRC16modbus (Crc, char_99_raw_message_buffer[i] );
	}
	Crc_LByte = (Crc & 0x00FF); 		// Low byte calculation
	Crc_HByte = (Crc & 0xFF00) / 256;	// High byte calculation

	char_99_raw_message_buffer[6] = Crc_LByte;
	char_99_raw_message_buffer[7] = Crc_HByte;

	transmit_data( char_99_raw_message_buffer, &l_num_bytes );
}

/***************************************************************
*
*   Description     * CRC16 calculation
*
****************************************************************/
unsigned int CRC16modbus(unsigned int crc, unsigned int data)
{
    const unsigned int Poly16=0xA001;
    unsigned int LSB, i;

    crc = ((crc^data) | 0xFF00) & (crc | 0x00FF);
    for (i=0; i<8; i++)
    {
        LSB=(crc & 0x0001); crc=crc/2;
        if (LSB)
        {
            crc=crc^Poly16;
        }
    }
    return(crc);
}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void transmit_spaced_message_table( char *char_ptr_original_message )
{
	char			char_99_encoded_message_buffer[ 99 ];
	char 			char_99_raw_message_buffer[ 99 ];
	char			char_99_original_message[ 99 ];
	long			l_num_bytes = 0;

    memset( char_99_original_message, '\0', 99 );
	memmove( &char_99_original_message[ 0 ], &char_ptr_original_message[0], 99 );
	memmove( &last_spaced_message[ 0 ], &char_ptr_original_message[0], 99 );

    remove_spaces_and_count_bytes( char_99_original_message, &l_num_bytes );
	convert_c_string_to_raw_message( &l_num_bytes, char_99_original_message, char_99_raw_message_buffer );
	encode_message( &l_num_bytes, char_99_raw_message_buffer, char_99_encoded_message_buffer );

	transmit_data( char_99_encoded_message_buffer, &l_num_bytes );

}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void transmit_spaced_messageHCRC( char *char_ptr_original_message )
{
	char			char_99_encoded_message_buffer[ 99 ];
	char 			char_99_raw_message_buffer[ 99 ];
	char			char_99_original_message[ 99 ];
	long			l_num_bytes = 0;
	char            *end;

    memset( char_99_original_message, '\0', 99 );
	memmove( &char_99_original_message[ 0 ], &char_ptr_original_message[0], 99 );
	memmove( &last_spaced_message[ 0 ], &char_ptr_original_message[0], 99 );

    remove_spaces_and_count_bytes( char_99_original_message, &l_num_bytes );
	convert_c_string_to_raw_message( &l_num_bytes, char_99_original_message, char_99_raw_message_buffer );

    // PLACE ADDRESS BEFORE CALCULATE HEADER CRC
    if( BACnet_Address[0] != 0 )
    {
        char_99_raw_message_buffer[3] = (uint8_t)strtoul(BACnet_Address, &end,16);
    }

    encode_messageHCRC( &l_num_bytes, char_99_raw_message_buffer, char_99_encoded_message_buffer );

	transmit_data( char_99_encoded_message_buffer, &l_num_bytes );
}


/***************************************************************
*
*   Description     * Function
*
****************************************************************/
void remove_spaces_and_count_bytes( char *char_ptr_the_message, long *l_num_of_bytes_ptr )
{
	int zz;
	int yy;

	*l_num_of_bytes_ptr = 1;

	for( zz = 0; zz < strlen( char_ptr_the_message ); ++zz )
	{	if( char_ptr_the_message[ zz ] == ' ' )
		{	for( yy = zz; yy < strlen( char_ptr_the_message ); ++yy )
			{
				char_ptr_the_message[ yy ] = char_ptr_the_message[ yy + 1 ];
			}
			--zz;
			++(*l_num_of_bytes_ptr);
		}
	}
}

/***************************************************************
*
*   Description     * Function
*
****************************************************************/
long count_spaced_message_bytes( char *char_ptr_the_message )
{
	int x;
	long num_bytes = 1;

	for( x = 0; x < strlen( char_ptr_the_message ); ++x )
	{	if( char_ptr_the_message[ x ] == ' ' )
        {
            ++num_bytes;
        }
	}
    return num_bytes;
}

/****************************************************************************************************

	Function converts communications string to raw format for serial transfer

	i.e. message of 4C 90 F0 3F

	Normal C String format( not including spaces )
		string[ 0 ] == 4
		string[ 1 ] == C
		string[ 2 ] == 9
		string[ 3 ] == 0
		string[ 4 ] == F
		string[ 5 ] == 0
		string[ 6 ] == 3
		string[ 7 ] == F

	Raw message format
		string[ 0 ] == 0x4C
		string[ 1 ] == 0x90
		string[ 2 ] == 0xF0
		string[ 3 ] == 0x3F

	New number of bytes of message is updated after conversion

****************************************************************************************************/
void convert_c_string_to_raw_message( long *l_num_bytes_ptr, char *char_ptr_string_to_convert, char *char_ptr_raw_message )
{
	char	char_99_raw_message[ 99 ];
	char	temp_char[ 3 ];
	char	*end;

	int		i_message_byte = 0;
	int		xx;

	memset( char_99_raw_message, '\0', 99 );

	// loop until counter expires or until message string completly converted
	for( xx = 0; xx < (*l_num_bytes_ptr * 2); xx+=2 ) 							// convert individual chars to bytes they really represent
	{
		sscanf( &char_ptr_string_to_convert[ xx ],"%c", &temp_char[ 0 ] );		// get MSB of byte
		sscanf( &char_ptr_string_to_convert[ xx + 1 ],"%c", &temp_char[ 1 ] );	// get LSB of byte

		temp_char[ 2 ] = '\0';

		// build messages byte by byte
		char_99_raw_message[ i_message_byte ] = (uint8_t)strtoul( temp_char, &end, 16 );
		++i_message_byte;
	}

	*l_num_bytes_ptr = i_message_byte;
	memmove( &char_ptr_raw_message[ 0 ], &char_99_raw_message[ 0 ], *l_num_bytes_ptr );
}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
#define DATA_START  8
#define DATA_LEN    6
void encode_message( long *l_num_bytes_ptr, char *char_ptr_message_to_encode, char *char_the_encoded_message_ptr )
{
	char			encoded_message[ 99 ];
	char 			original_message[ 99 ];
	short			i=0,j=0;
	uint8_t         tcrc = 0xFF;
    uint16_t        hcrc = 0xFFFF;
    uint16_t        dcrc = 0x0000;

	memset( encoded_message, '\0', 99 );
	memset( original_message, '\0', 99 );


	for( i = 0; i < *l_num_bytes_ptr; ++i )
		original_message[ i ] = char_ptr_message_to_encode[ i ];

	for(i = 0; i < *l_num_bytes_ptr; i++ )
	{
        encoded_message[j++]=original_message[i];
	}

    tcrc = CalcHeaderCRC((uint8_t)(encoded_message[2]&0xFF),tcrc);
	tcrc = CalcHeaderCRC(encoded_message[3],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[4],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[5],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[6],tcrc);
	encoded_message[7] = (~tcrc);

    j=0;
    if((uint8_t)encoded_message[DATA_LEN] > (uint8_t)0)
    {
        for(i = 0; i < encoded_message[DATA_LEN]; ++i)
        {
            j = DATA_START + i;
            hcrc = CalcDataCRC((uint8_t)encoded_message[j], hcrc);
        }

        hcrc = ~hcrc;

        encoded_message[(uint8_t)encoded_message[DATA_LEN]+8]=(uint8_t)(hcrc&0x00FF);
        encoded_message[(uint8_t)encoded_message[DATA_LEN]+9]=(uint8_t)((hcrc>>8)&0x00FF);

        dcrc = hcrc;
    }

	memmove( &char_the_encoded_message_ptr[ 0 ], &encoded_message[ 0 ], *l_num_bytes_ptr );
}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 Æ
 ¤   Description     ¤ Function
 ¤
 Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void encode_messageHCRC( long *l_num_bytes_ptr, char *char_ptr_message_to_encode, char *char_the_encoded_message_ptr )
{
	char			encoded_message[ 99 ];
	char 			original_message[ 99 ];
	short			i=0,j=0;
	uint8_t         tcrc = 0xFF;

	memset( encoded_message, '\0', 99 );
	memset( original_message, '\0', 99 );


	for( i = 0; i < *l_num_bytes_ptr; ++i )
		original_message[ i ] = char_ptr_message_to_encode[ i ];

	for(i = 0; i < *l_num_bytes_ptr; i++ )
	{
        encoded_message[j++]=original_message[i];
	}

    tcrc = CalcHeaderCRC((uint8_t)(encoded_message[2]&0xFF),tcrc);
	tcrc = CalcHeaderCRC(encoded_message[3],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[4],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[5],tcrc);
	tcrc = CalcHeaderCRC(encoded_message[6],tcrc);
	encoded_message[7] = (~tcrc);

	memmove( &char_the_encoded_message_ptr[ 0 ], &encoded_message[ 0 ], *l_num_bytes_ptr );
}


uint8_t CalcHeaderCRC( uint8_t dv, uint8_t cv )
{
	uint16_t crc;

	crc=cv^dv;

	crc = (uint16_t)(crc^(crc<<1)^(crc<<2)^(crc<<3)^(crc<<4)^(crc<<5)^(crc<<6)^(crc<<7));

	return (uint8_t)((crc&0xFE)^((crc>>8)&1));        //wrote = write( gateway, char_ptr_original_message, the_message_length );

}

uint16_t CalcDataCRC(uint8_t dv, uint16_t cv)
{
    uint16_t	crcLow;

    crcLow=(cv&0xFF)^dv;

    return (uint16_t)((cv>>8)^(crcLow<<8)^(crcLow<<3)^(crcLow<<12)^(crcLow>>4)^(crcLow&0x0F)^((crcLow&0x0F)<<7));
}


/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void transmit_data( char *char_ptr_original_message, long *l_message_length  )
{
	long			the_message_length = *l_message_length;
	int				wrote = 0;

	if( gateway != 0 )
    {
        wrote = write( gateway, char_ptr_original_message, the_message_length );
    }
}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void convert_raw_message_to_c_string( long *l_num_bytes_ptr, char *char_ptr_message_to_convert, char *char_ptr_stringed_message )
{
	int		xx;
	int		yy;
	uint8_t	uint8_temp;
	long	l_new_bytes = *l_num_bytes_ptr;

	yy = 0;
	for( xx = 0; xx < *l_num_bytes_ptr; ++xx )
	{
		uint8_temp = (uint8_t)0xF0 & (uint8_t)char_ptr_message_to_convert[ xx ];
		uint8_temp = uint8_temp >> 4;
		sprintf( &char_ptr_stringed_message[ yy ], "%X", uint8_temp );

		uint8_temp = (uint8_t)0x0F & (uint8_t)char_ptr_message_to_convert[ xx ];
		sprintf( &char_ptr_stringed_message[ yy + 1 ], "%X", uint8_temp );
		yy+=2;
		++l_new_bytes;
	}

	// add some spaces for visual purposes
	for( xx = 2; xx <= strlen( char_ptr_stringed_message ) - 1; xx+=3 )
	{
		memmove( &char_ptr_stringed_message[ xx + 1 ], &char_ptr_stringed_message[ xx ], l_new_bytes );
		char_ptr_stringed_message[ xx ] = ' ';
		--l_new_bytes;
	}

}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
 Æ
 ¤   Description     ¤ Function
 ¤
 Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void convert_raw_message_to_c_string_no_spaces( long *l_num_bytes_ptr, char *char_ptr_message_to_convert, char *char_ptr_stringed_message )
{
	int		xx;
	int		yy;
	uint8_t	uint8_temp;
	long	l_new_bytes = *l_num_bytes_ptr;

	yy = 0;
	for( xx = 0; xx < *l_num_bytes_ptr; ++xx )
	{
		uint8_temp = (uint8_t)0xF0 & (uint8_t)char_ptr_message_to_convert[ xx ];
		uint8_temp = uint8_temp >> 4;
		sprintf( &char_ptr_stringed_message[ yy ], "%X", uint8_temp );

		uint8_temp = (uint8_t)0x0F & (uint8_t)char_ptr_message_to_convert[ xx ];
		sprintf( &char_ptr_stringed_message[ yy + 1 ], "%X", uint8_temp );
		yy+=2;
		++l_new_bytes;
	}
}


/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void emulation( char *message )
{
//	char registration_request[]		= "B0 00 19 00 1F FF 04 01 11 13 60";
//	char registration_reply[]        = "B0 01 19 0F 04 00 FD 01 03";
//	char registration_completion[]   = "B0 01 19 0F 04 00 FD 01 01";

	// CHECK PASSED IN MESSAGE FOR REGISTRATION REQUEST
	// AND SEND THE REGISTRATION REPLY AND REGISTRATION
	// COMPLETION RESPONSES IF FOUND
	//if( memcmp( message, &registration_request, strlen( registration_request ) ) == 0 )
	//{	transmit_spaced_message( registration_reply );
	//	transmit_spaced_message( registration_completion );
	//}
}


/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void serial_receive( char *serial_receive_buffer )
{
	char			char_99_buffer[ 99 ];
	char			char_99_buffer2[ 99 ];
	char			char_1_buffer[ 1 ];
	bool			b_found_bpreamble = NO;
	bool			b_found_epreamble = NO;
	long				x = 0;
	int                 timer = 0;
	int                 tries = 0;
    bool            timeout = NO;
	//MPSemaphoreID       sem_id_delay;

    // CREATE A BINARY SEMAPHORE
	//MPCreateSemaphore( 1, 0, &sem_id_delay );

	memset( char_99_buffer, '\0', 99 );

	x = 0;
	b_found_bpreamble = FALSE;


    while( ( timeout == NO ) && ( b_found_bpreamble == NO ) )
    {
        // TIME OUT AFTER 1 SECOND
        while( ( b_found_bpreamble == NO ) && ( timer < 1000 ) )
        {
            //MPWaitOnSemaphore( sem_id_delay, 1 * kDurationMillisecond );
            usleep(1000);
            ++timer;

            if( read( gateway, char_1_buffer, 1 ) >= 1 )
            {
                memmove( &char_99_buffer[ x ], &char_1_buffer[ 0 ], 1 );

                // FIND BEGINNING BACNET PREAMBLE
                if( (uint8_t)0x55 == (uint8_t)char_99_buffer[ x ] )
                {	read( gateway, char_1_buffer, 1 );
                     ++x;

                    if( (uint8_t)0xFF == (uint8_t)char_1_buffer[ 0 ] )
                    {
                        memmove( &char_99_buffer[ x ], &char_1_buffer[ 0 ], 1 );
                        b_found_bpreamble = YES;
                        ++x;
                    }
                }
                else
                    ++x;
            }
            // MPYield();
        }

        // FIND ENDING BACNET PREAMBLE
        while( ( b_found_epreamble == NO ) && ( timer < 1000 ) )
        {
            //MPWaitOnSemaphore( sem_id_delay, 1 * kDurationMillisecond );
            usleep(1000);
            ++timer;

            if( read( gateway, char_1_buffer, 1 ) >= 1 )
            {
                memmove( &char_99_buffer[ x ], &char_1_buffer[ 0 ], 1 );

                // FIND ENDING BACNET PREAMBLE
                if( (uint8_t)0x55 == (uint8_t)char_99_buffer[ x ] )
                {	read( gateway, char_1_buffer, 1 );
                    ++x;

                    if( (uint8_t)0xFF == (uint8_t)char_1_buffer[ 0 ] )
                    {
                        memmove( &char_99_buffer[ x ], &char_1_buffer[ 0 ], 1 );
                        b_found_epreamble = YES;
                        ++x;
                    }
                }
                else
                    ++x;
            }
            //MPYield();
        }


        if( timer >= 1000 )
        {
            transmit_spaced_message( last_spaced_message );
            ++tries;
        }
        if( tries >= 3 )
        {
            timeout = YES;
        }
    }

    if( timeout == YES )
    {
       test_command( "BACnet ERROR" );
       test_name("Timed Out Waiting For Message");
    }
    else
    {
        convert_raw_message_to_c_string( &x, char_99_buffer, char_99_buffer2 );
        sprintf( serial_receive_buffer, "%s", char_99_buffer2 );
    }
}

void serial_receive_modbus( char *serial_receive_buffer )
{
	char			char_99_buffer[ 99 ];
	char			char_1_buffer[ 1 ];
	bool			b_found_bpreamble = NO;
	long				x = 0;
	int                 timer = 0;
    bool            timeout = NO;

	memset( char_99_buffer, '\0', 99 );

	x = 0;
	b_found_bpreamble = FALSE;


    while( ( timeout == NO ) && ( b_found_bpreamble == NO ) )
    {
        // TIME OUT AFTER 1 SECOND
        while( ( b_found_bpreamble == NO ) && ( timer < 1000 ) )
        {
            //MPWaitOnSemaphore( sem_id_delay, 1 * kDurationMillisecond );
            usleep(1000);
            ++timer;

            if( read( gateway, char_1_buffer, 1 ) >= 1 )
            {
                memmove( &char_99_buffer[ x ], &char_1_buffer[ 0 ], 1 );

                // FIND BEGINNING ADDRESS
                if( (uint8_t)modbus_address_hex == (uint8_t)char_99_buffer[ x ] )
                {
                    read( gateway, &char_99_buffer[1], 7 );
                    b_found_bpreamble = YES;
                }
            }
            //MPYield();
        }
    }

    if( timeout == YES )
    {
        test_command( "MODBUS ERROR" );
        test_name("Timed Out Waiting For Message");
    }
    else
    {
        memmove( &serial_receive_buffer[ 0 ], &char_99_buffer[0], 99 );
    }
}

void serial_receive_bacnet( char * serial_receive_buffer )
{
    bool                     b_found_preamble = NO;
    long                        x = 0;
    long                        message_length = 0;
    uint8_t                       uint8_message_length = 0;
    uint8_t                        char_1_buffer[ 1 ];
    static char                 char_99_raw_bytes[ 99 ];

    if( gateway < 0 )
    {
        return;
    }

    x = 0;

    if( read( gateway, char_1_buffer, 1 ) >= 1 )
    {
        while( b_found_preamble == NO )
        {
            // FIND PREAMBLE AND SYNCRONIZE COMMUNICATIONS
            if( (uint8_t)0x55 == (uint8_t)char_1_buffer[ 0 ] )
            {
                char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

                read( gateway, char_1_buffer, 1 );

                if( (uint8_t)0xFF == (uint8_t)char_1_buffer[ 0 ] )
                {
                    ++x;
                    char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
                    b_found_preamble = YES;
                }
            }

            if( b_found_preamble != YES )
            {
                read( gateway, char_1_buffer, 1 );
            }
        }

        // GET FRAME TYPE
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET DESTINATION ADDRESS
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET SOURCE ADDRESS
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET LENGTH MSB
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET LENGTH LSB
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        message_length = (uint8_t)char_1_buffer[ 0 ];
        uint8_message_length = (uint8_t)char_1_buffer[ 0 ];

        if(message_length > 98 )
        {
            message_length = 0;
        }

        if(message_length)
        {
            while( message_length >= 0  )    // LSB
            {
                read( gateway, char_1_buffer, 1 );
                ++x;
                char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
                message_length = message_length - 1;
            }
        }

        // GET MSB CRC
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // IF DATA LENGTH GREATER THAN ZERO THEN GET SECOND DATA CRC, OTHERWISE ONLY GET HEADER CRC ABOVE
        if( uint8_message_length != 0x00 )
        {   // GET LSB CRC
            read( gateway, char_1_buffer, 1 );
            ++x;
            char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
        }

        ++x;

        //convert_raw_message_to_c_string_no_spaces( &x, char_99_raw_bytes, serial_receive_buffer );
        memmove( &serial_receive_buffer[ 0 ], &char_99_raw_bytes[0], 99 );
    }
}

void serial_receive_bacnet_bytes( char * serial_receive_buffer, long * num_bytes )
{
    bool                     b_found_preamble = NO;
    long                        x = 0;
    long                        message_length = 0;
    uint8_t                       uint8_message_length = 0;
    uint8_t                        char_1_buffer[ 1 ];
    static char                 char_99_raw_bytes[ 99 ];

    if( gateway < 0 )
    {
        return;
    }

    x = 0;

    if( read( gateway, char_1_buffer, 1 ) >= 1 )
    {
        while( (b_found_preamble == NO) && !check_for_abort() )
        {
            // FIND PREAMBLE AND SYNCRONIZE COMMUNICATIONS
            if( (uint8_t)0x55 == (uint8_t)char_1_buffer[ 0 ] )
            {
                char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

                read( gateway, char_1_buffer, 1 );

                if( (uint8_t)0xFF == (uint8_t)char_1_buffer[ 0 ] )
                {
                    ++x;
                    char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
                    b_found_preamble = YES;
                }
            }

            if( b_found_preamble != YES )
            {
                read( gateway, char_1_buffer, 1 );
            }
        }

        if(check_for_abort())
        {
            close_gateway_serial_port();
        }

        // GET FRAME TYPE
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET DESTINATION ADDRESS
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET SOURCE ADDRESS
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET LENGTH MSB
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // GET LENGTH LSB
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        message_length = (uint8_t)char_1_buffer[ 0 ];
        uint8_message_length = (uint8_t)char_1_buffer[ 0 ];

        if(message_length > 98 )
        {
            message_length = 0;
        }

        if(message_length)
        {
            while( message_length >= 0  )    // LSB
            {
                read( gateway, char_1_buffer, 1 );
                ++x;
                char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
                message_length = message_length - 1;
            }
        }

        // GET MSB CRC
        read( gateway, char_1_buffer, 1 );
        ++x;
        char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];

        // IF DATA LENGTH GREATER THAN ZERO THEN GET SECOND DATA CRC, OTHERWISE ONLY GET HEADER CRC ABOVE
        if( uint8_message_length != 0x00 )
        {   // GET LSB CRC
            read( gateway, char_1_buffer, 1 );
            ++x;
            char_99_raw_bytes[ x ] = (uint8_t)char_1_buffer[ 0 ];
        }

        ++x;

        memmove( &serial_receive_buffer[ 0 ], &char_99_raw_bytes[0], 99 );
        *num_bytes = x;
    }

}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void set_expected_response( char *expected_message )
{
    memmove( &expected_message_buffer[0], &expected_message[0], 99);
}

/* ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
Æ
¤   Description     ¤ Function
¤
Æ  ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿*/
void get_expected_response( char *expected_response )
{
	char    char_raw_message[99];
    long    num_bytes;

    while( found_message_notification == NO )
	{
	}
    found_message_notification = NO;

    num_bytes = count_spaced_message_bytes( expected_response_buffer );
    remove_c_spaces(expected_response_buffer);

    convert_c_string_to_raw_message( &num_bytes, expected_response_buffer, char_raw_message );

	memmove( &expected_response[0], &char_raw_message[0], 99 );
}

void * Memmove(void* pvDst, const void* pvSrc, unsigned int n)
{
    char *prgcBuffer=NULL;
    char *pcSource =(char *)pvSrc;
    char *pcDstn =(char *)pvDst;
    short siIndex=0;

    prgcBuffer=(char*)malloc(n);
    if(NULL == prgcBuffer)
    {
        return NULL;
    }
    else
    {
        for(;siIndex<n;siIndex++)
        {
            prgcBuffer[siIndex]=pcSource[siIndex];
        }
        for(siIndex=0;siIndex<n;siIndex++)
        {
            pcDstn[siIndex]=prgcBuffer[siIndex];
        }
        memcpy(pcDstn,prgcBuffer,n);

        free(prgcBuffer);
  }

    return pvDst;
}
