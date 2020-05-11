/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  MAIN_WIN                         1
#define  MAIN_WIN_TEST_NAME               2       /* control type: string, callback function: test_name_callback */
#define  MAIN_WIN_TEST_DATA               3       /* control type: string, callback function: test_data_callback */
#define  MAIN_WIN_TEST_COMMAND            4       /* control type: string, callback function: test_command_callback */
#define  MAIN_WIN_LIMITS_TABLE            5       /* control type: table, callback function: limits_table_callback */
#define  MAIN_WIN_SINGLE_BUTTON           6       /* control type: command, callback function: single_test_button_callback */
#define  MAIN_WIN_RUN_BUTTON              7       /* control type: command, callback function: run_tests_button_callback */
#define  MAIN_WIN_TEST_PROGRESS           8       /* control type: scale, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUBAR                          1
#define  MENUBAR_MENU_FILE                2       /* callback function: menu_file_callback */
#define  MENUBAR_MENU_OPEN                3       /* callback function: menu_open_callback */
#define  MENUBAR_MENU_QUIT                4       /* callback function: menu_quit_callback */


     /* Callback Prototypes: */

int  CVICALLBACK limits_table_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK menu_file_callback(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK menu_open_callback(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK menu_quit_callback(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK run_tests_button_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK single_test_button_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK test_command_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK test_data_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK test_name_callback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif