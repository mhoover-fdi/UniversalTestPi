//
//  BKMETER.h
//  Universal Test copy
//
//  Created by Matt Hoover Tester Build on 9/21/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

int     open_BK5491_serial_port( void );
void    close_BK5491_serial_port( void );
int     init_BK5491( void );
int     BK5491_send( char *char_ptr_original_message, long *l_message_length  );
void    BK5491_receive( char *serial_receive_buffer );
double  dcv_measure_BK5491(void);
double acv_measure_BK5491( void );
double  diode_measure_BK5491( void );
void    measure_BK5491(void);
void    dcv_BK5491(void);
void    acv_BK5491(void);
void    res_BK5491(void);
void    freq_BK5491(void);
void    diode_BK5491(void);
void    cont_BK5491(void);

int open_dmm_panel ( void);
