//
//  LabJackIO.m
//  Universal Test copy
//
//  Created by Matt Hoover Tester Build on 9/23/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#include "LabJackIO.h"
//#include "LonTest.h"

//#include <unistd.h>
#include "u3.h"

HANDLE hDeviceDMM = 0;
HANDLE hDeviceJIG = 0;
HANDLE hDeviceDAC = 0;

long    state;


HANDLE HandleJIG( void )
{
    return hDeviceJIG;
}

HANDLE HandleDMM( void )
{
    return hDeviceDMM;
}

HANDLE HandleDAC( void )
{
    return hDeviceDAC;
}

void open_lab_jacks( void )
{
    if( hDeviceJIG == 0 )
    {
        hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
    }
    
    if( hDeviceDMM == 0 )
    {
        hDeviceDMM = LJUSB_OpenDevice( U3_DMM, 0, U3_PRODUCT_ID);
    }
    if( hDeviceDAC == 0 )
    {
        hDeviceDMM = LJUSB_OpenDevice( U3_DAC, 0, U3_PRODUCT_ID);
    }
    
}

void close_lab_jacks( void )
{
    if( hDeviceJIG != 0 )
    {
        closeUSBConnection(hDeviceJIG);
    }
    if( hDeviceDMM != 0 )
    {
        closeUSBConnection(hDeviceDMM);
    }
    if( hDeviceDAC != 0 )
    {
        closeUSBConnection(hDeviceDAC);
    }
}

void initialize_lab_jack( void )
{
    long    cart_indentifier = -1;
    long    i_o_State = 0;
    
    
    hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
    hDeviceDAC = LJUSB_OpenDevice( U3_DAC, 0, U3_PRODUCT_ID);
    hDeviceDMM = LJUSB_OpenDevice( U3_DMM, 0, U3_PRODUCT_ID);
}
void application_terminate_labjack( void )
{
    if( hDeviceJIG != 0 )
    {
        closeUSBConnection(hDeviceJIG);
    }
    if( hDeviceDMM != 0 )
    {
        closeUSBConnection(hDeviceDMM);
    }
    if( hDeviceDAC != 0 )
    {
        closeUSBConnection(hDeviceDAC);
    }
}

void open_lab_jack( void )
{
    hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
    hDeviceDMM = LJUSB_OpenDevice( U3_DMM, 0, U3_PRODUCT_ID);
    hDeviceDAC = LJUSB_OpenDevice( U3_DAC, 0, U3_PRODUCT_ID);
}

void close_lab_jack( void )
{
    closeUSBConnection(hDeviceJIG);
    closeUSBConnection(hDeviceDMM);
    closeUSBConnection(hDeviceDAC);
}
