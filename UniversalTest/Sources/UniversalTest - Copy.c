#include <cviauto.h>
#include <cvirte.h>		
#include <userint.h>
#include <progressbar.h>
#include <toolbox.h>

#include "UniversalTest.h"
#include "TestModel.h"
#include "TestStandard.h"

static int mainWin;

int main (int argc, char *argv[])
{
    int error = 0;
    char *errer_description = 0;

 if (InitCVIRTE (0, argv, 0) == 0)
        return -1;  /* out of memory */
    if ((mainWin = LoadPanel (0, "UniversalTest.uir", MAIN_WIN)) < 0)
        return -1;
    error = ProgressBar_ConvertFromSlide (mainWin, MAIN_WIN_TEST_PROGRESS);
    errer_description = GetGeneralErrorString (error);
    error = ProgressBar_SetAttribute (mainWin, MAIN_WIN_TEST_PROGRESS, ATTR_PROGRESSBAR_UPDATE_MODE, VAL_PROGRESSBAR_MARQUEE_MODE);
    errer_description = GetGeneralErrorString (error);
    error = ProgressBar_Start (mainWin, MAIN_WIN_TEST_PROGRESS, "");
    
//    SetCtrlAttribute(mainWin, MAIN_WIN_TEST_PROGRESS, ATTR_MIN_VALUE, 1);
//    SetCtrlAttribute(mainWin, MAIN_WIN_TEST_PROGRESS, ATTR_MAX_VALUE, 19);
//    SetCtrlVal (get_main_win(), MAIN_WIN_TEST_PROGRESS, ATTR_CTRL_STYLE, ATTR_USE_PROGRESS_BAR_VISUAL_STYLES);
    
    SetCtrlAttribute (mainWin, MAIN_WIN_TEST_COMMAND, ATTR_NO_EDIT_TEXT, 1);
    SetCtrlAttribute (mainWin, MAIN_WIN_TEST_NAME, ATTR_NO_EDIT_TEXT, 1);
    SetCtrlAttribute (mainWin, MAIN_WIN_TEST_DATA, ATTR_NO_EDIT_TEXT, 1);
    SetTableSelection(mainWin,MAIN_WIN_LIMITS_TABLE,VAL_TABLE_ROW_RANGE(1));
    
    test_command("Universal Test 0.1");
    
    CA_InitActiveXThreadStyleForCurrentThread(0,COINIT_APARTMENTTHREADED); // must call first before active x speech modifies thread
    speak_string( "Welcome To Universal Test" );
     
    DisplayPanel (mainWin);
    RunUserInterface ();
    DiscardPanel (mainWin);
    return 0;
    
Error:
	DiscardPanel (mainWin);
	return 0;
}

int CVICALLBACK test_command_callback (int panel, int control, int event,
                                       void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
        	case EVENT_LEFT_CLICK_UP:
                SetCtrlAttribute (mainWin, MAIN_WIN_TEST_COMMAND, ATTR_NO_EDIT_TEXT, 1);
                test_command("Universal Test 0.1");
                break;
            case EVENT_COMMIT:
            case EVENT_RIGHT_CLICK:
            case EVENT_LEFT_CLICK:
            case EVENT_LEFT_DOUBLE_CLICK:
            return 1;
  default:
            break;
    }
    return 0;
}

int CVICALLBACK single_test_button_callback (int panel, int control, int event,
        void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
		case EVENT_LEFT_CLICK_UP:
            run_single_test();
            
			break;

            case EVENT_COMMIT:
            case EVENT_RIGHT_CLICK:
            case EVENT_LEFT_CLICK:
            return 1;

            break;
    }
    return 0;
}

int CVICALLBACK run_tests_button_callback (int panel, int control, int event,
        void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
		case EVENT_LEFT_CLICK_UP:
            run_tests();
            break;
            
        case EVENT_COMMIT:

            break;
    }
    return 0;
}

void CVICALLBACK menu_file_callback (int menuBar, int menuItem, void *callbackData,
                                     int panel)
{
}

void CVICALLBACK menu_open_callback (int menuBar, int menuItem, void *callbackData,
                                     int panel)
{
    open_limits_file();
}

void CVICALLBACK menu_quit_callback (int menuBar, int menuItem, void *callbackData,
                                     int panel)
{
    speak_string( "Thank You For Using Universal Test" );
    Delay(3);
    QuitUserInterface (0);
}

int get_main_win( void )
{
    return mainWin;
}

int CVICALLBACK limits_table_callback (int panel, int control, int event,
                                       void *callbackData, int eventData1, int eventData2)
{
    Point cell;
    // MakeRect
    /*Name Type  Description 
     top    int  Location of the top edge of the rectangle. 
     left   int  Location of the left edge of the rectangle. 
     height int  Height of the rectangle. 
     width  int  Width of the rectangle. 
    */
    switch (event)
    {
		case EVENT_LEFT_CLICK_UP:
			GetTableCellFromPoint(panel,control,MakePoint(eventData2,eventData1),&cell);
			if (cell.x == 0 && cell.y == 0) return 1; // Not on a row/col
			SetTableSelection(panel,control,MakeRect(2, 2, 4, 3));
			//SetTableSelection(panel,control,MakeRect(cell.y, cell.x, 1, 6));
            SetTableSelection(panel,control,VAL_TABLE_ROW_RANGE(cell.y));
            set_active_test_row(cell.y);
			break;
        
        case EVENT_COMMIT:

            break;
        case EVENT_LEFT_CLICK:
            return 1;
            break;

            
        case EVENT_DRAG:
            return 1;
            break;
    }
    return 0;
}

int CVICALLBACK test_data_callback (int panel, int control, int event,
                                    void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
            case EVENT_COMMIT:
            case EVENT_RIGHT_CLICK:
            case EVENT_LEFT_CLICK:
            case EVENT_LEFT_DOUBLE_CLICK:
            return 1;

            break;
    }
    return 0;
}

int CVICALLBACK test_name_callback (int panel, int control, int event,
                                    void *callbackData, int eventData1, int eventData2)
{
    switch (event)
    {
            case EVENT_COMMIT:
            case EVENT_RIGHT_CLICK:
            case EVENT_LEFT_CLICK:
            case EVENT_LEFT_DOUBLE_CLICK:
            return 1;

            break;
    }
    return 0;
}
