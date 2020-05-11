//
//  LabJackIO.m
//  Universal Test copy
//
//  Created by Matt Hoover Tester Build on 9/23/10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//
#include "../headers/LabJackM.h"
//#include "LabJackUD.h"

//#include "LabJackIO.h"
#include "../headers/LabJackIO.h"

#include "../headers/TestModel.h"

#include <unistd.h>
#include "../headers/u3.h"

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
//    LJ_ERROR    err = -1;
//	long        lngErrorcode = 0;
 //   char        lj_error_buffer[45];

/*
    if( hDeviceJIG == -1 )
    {
        //hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
        err = OpenLabJack (LJ_dtU3, LJ_ctUSB, "1", 0, &hDeviceJIG);

        if(err != 0 )
        {
            //ErrorToString(lngErrorcode,err);
            sprintf(lj_error_buffer, "LabJack U3-LV Error Code = %d",err);
            //MessagePopup("Error", lj_error_buffer);
        }
    }
*/
    if( hDeviceJIG == 0 )
    {
        hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
         //err = LJM_Open(LJM_dtANY, LJM_ctANY, "LJM_idANY", &handle);
    }
    if( hDeviceDMM == 0 )
    {
        hDeviceDMM = LJUSB_OpenDevice( U3_DMM, 0, U3_PRODUCT_ID);
         //err = LJM_Open(LJM_dtT4, LJM_ctUSB, "LJM_idANY", &handle);
    }
    if( hDeviceDAC == 0 )
    {
        hDeviceDMM = LJUSB_OpenDevice( U3_DAC, 0, U3_PRODUCT_ID);
         //err = LJM_Open(LJM_dtT4, LJM_ctUSB, "LJM_idANY", &handle);
    }


}

void close_lab_jacks( void )
{

    if( hDeviceJIG != 0)
    {
        closeUSBConnection(hDeviceJIG);
        hDeviceJIG = 0;
    }
    if( hDeviceDMM != 0)
    {
        closeUSBConnection(hDeviceDMM);
        hDeviceDMM = 0;
    }
    if( hDeviceDAC != 0)
    {
        closeUSBConnection(hDeviceDAC);
        hDeviceDAC = 0;
   }



   //Close();
   //hDeviceJIG = -1;
}
/*
void application_terminate_labjack( void )
{
    Close();
}
*/

/*
void open_lab_jack( void )
{
    int err = 0;

    //if( hDeviceJIG == 0 )
    //{
        //hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
        err = LJM_Open(LJ_dtU3, LJM_ctUSB, "LJM_idANY", &hDeviceJIG);
    //}
    //hDeviceJIG = LJUSB_OpenDevice( U3_JIG, 0, U3_PRODUCT_ID);
    //hDeviceDMM = LJUSB_OpenDevice( U3_DMM, 0, U3_PRODUCT_ID);
    //hDeviceDAC = LJUSB_OpenDevice( U3_DAC, 0, U3_PRODUCT_ID);
}
*/
/*
void close_lab_jack( void )
{
    Close();
}
*/
