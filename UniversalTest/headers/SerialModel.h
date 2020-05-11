/* SerialModel */

//#import <Cocoa/Cocoa.h>
#include <sys/types.h>
#include <stdint.h>

#define DEFAULT_BAUD_9600

void    close_gateway_serial_port( void );
void    convert_c_string_to_raw_message( long *l_num_bytes_ptr, char *char_ptr_string_to_convert, char *char_ptr_raw_message );
void    convert_raw_message_to_c_string( long *l_num_bytes_ptr, char *char_ptr_message_to_convert, char *char_ptr_stringed_message );
void    encode_message( long *l_num_bytes_ptr, char *char_ptr_message_to_encode, char *char_the_encoded_message_ptr );
void    init_gateway( void );
bool    open_gateway_serial_port( void );
void    remove_spaces_and_count_bytes( char *char_ptr_the_message, long *l_num_of_bytes_ptr );
void    transmit_data( char *char_ptr_original_message, long *l_message_length  );
void    transmit_spaced_message( char *char_ptr_original_message );
void    transmit_spaced_message_table( char *char_ptr_original_message );
void    transmit_un_spaced_message( char *char_ptr_original_message );
void    emulation( char *message );
void    serial_receive( char *serial_receive_buffer );
void    serial_receive_bacnet( char * message_data );
void serial_receive_bacnet_bytes( char * serial_receive_buffer, long * num_bytes );
void    serial_receive_modbus( char *serial_receive_buffer );

void    transmit_spaced_message_modbus( char *char_ptr_original_message );
unsigned int CRC16modbus(unsigned int crc, unsigned int data);

int     t_read( int gateway, char *out_buffer, int bytes );
uint8_t CalcHeaderCRC(uint8_t dv, uint8_t cv);
uint16_t CalcDataCRC(uint8_t dv, uint16_t cv);

void    transmit_spaced_messageHCRC( char *char_ptr_original_message );
void    encode_messageHCRC( long *l_num_bytes_ptr, char *char_ptr_message_to_encode, char *char_the_encoded_message_ptr );
void * Memmove(void* pvDst, const void* pvSrc, unsigned int n);

