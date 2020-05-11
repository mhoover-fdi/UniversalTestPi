//
//  LabJackIO.h
//  Universal Test copy
//
//  Created by Matt Hoover Tester Build on 9/23/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

//#import <Cocoa/Cocoa.h>
//#include <unistd.h>
//#include "u3.h"
//#include "LabJackUD.h"
#include "labjackusb.h"

#define U3_JIG  1
#define U3_DAC  2
#define U3_DMM  3

#define FIO0    0
#define FIO1    1
#define FIO2    2
#define FIO3    3
#define FIO4    4
#define FIO5    5
#define FIO6    6
#define FIO7    7

#define EIO0    8
#define EIO1    9
#define EIO2    10
#define EIO3    11
#define EIO4    12
#define EIO5    13
#define EIO6    14
#define EIO7    15

#define CIO0    16
#define CIO1    17
#define CIO2    18
#define CIO3    19

#define FIO0_ON    20
#define FIO1_ON    21
#define FIO2_ON    22
#define FIO3_ON    23
#define FIO4_ON    24
#define FIO5_ON    25
#define FIO6_ON    26
#define FIO7_ON    27

#define EIO0_ON    28
#define EIO1_ON    29
#define EIO2_ON    30
#define EIO3_ON    31
#define EIO4_ON    32
#define EIO5_ON    33
#define EIO6_ON    34
#define EIO7_ON    35

#define CIO0_ON    36
#define CIO1_ON    37
#define CIO2_ON    38
#define CIO3_ON    39

#define ON      1
#define OFF     0



int test_labjack_connected( void );
HANDLE HandleJIG( void );
HANDLE HandleDMM( void );
void open_lab_jacks( void );
void close_lab_jacks( void );
