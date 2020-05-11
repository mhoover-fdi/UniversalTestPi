#include <gtk/gtk.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include "../main.h"
#include "../headers/TestModel.h"
#include "../headers/TestStandard.h"
#include "../headers/TTspeech.h"
#include "../headers/audio.h"

bool start = NO;
bool single_test = NO;
bool do_abort = NO;
bool failure = NO;
bool testing = NO;


int     file_open_error = -1;
FILE    *the_limits_file_fp;
ssize_t limits_file_size;
char    *file_buffer_malloc = NULL;
char    *end;
char    line[300];
char    *token = NULL;
int     pos = 0;
int     pos2 = 0;
char    char_33_temp[33];
char    char_33_temp_lo[33];
char    char_33_temp_hi[33];
int     the_test_index = 0;
int     int_num_table_rows = 0;
int     int_number_of_tests = 0;
int     active_table_test_row = 1;
bool    stop_testing = NO;
int     selected_row_index = 0;
char*   filename;
int     test_row_tag_id;
int     update_pass_fail_column_idle_id;
int     update_measurement_column_idle_id;
int     update_progress_bar_idle_id;


struct test_list_data_struct the_test_list_array[199];


void open_limits_file(GtkWidget *widget, gpointer data)
{
    int xx = 0;
    int row = 0;
    GtkWidget *dialog;
    GtkDialogFlags flags = GTK_DIALOG_DESTROY_WITH_PARENT;
    gint res;
    GtkTreeIter iterator;
    GdkColor color;

    the_test_index = 0;

    set_failure(NO);

    dialog = gtk_file_chooser_dialog_new ("Open Limits File",NULL,GTK_FILE_CHOOSER_ACTION_OPEN,"_Cancel",GTK_RESPONSE_CANCEL,"_Open",GTK_RESPONSE_ACCEPT,NULL);

    res = gtk_dialog_run (GTK_DIALOG (dialog));

    if (res == GTK_RESPONSE_ACCEPT)
    {
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        filename = gtk_file_chooser_get_filename (chooser);
        gtk_widget_destroy (dialog);

    }
    else
    {
        dialog = gtk_message_dialog_new (NULL,flags,GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,"No File Selected",filename,g_strerror (errno));
        gtk_dialog_run (GTK_DIALOG (dialog));
        gtk_widget_destroy (dialog);
        return;
    }

    set_failure( NO );

    //speak_string( "You've chosen a fine RIB to test" );

    // OPEN FILE READ ONLY
    the_limits_file_fp = fopen(filename, "r" );

    // CHECK FOR ERROR AND DISPLAY MESSAGE DIALOG IF THERE IS
    if( the_limits_file_fp == NULL )
    {
        dialog = gtk_message_dialog_new (NULL,flags,GTK_MESSAGE_ERROR,GTK_BUTTONS_CLOSE,"No File Selected",filename,g_strerror (errno));
        gtk_dialog_run (GTK_DIALOG (dialog));
        gtk_widget_destroy (dialog);
    }

    // PARSE CSV LIMITS FILE TO PLACE IN ARRAY FOR UI TreeView
    // get limits parameters loop
	while( ( feof( the_limits_file_fp ) == 0 ) && ( xx < MAX_TESTS ) )
	{
        fgets( line, 300, the_limits_file_fp );

		if( feof( the_limits_file_fp ) != 0 )
			break;
        if( strstr(line, "EOF"))
            break;

		// point to first instance of ,
		token = strpbrk( line, "," );

		//	Get test name
		/******************************************************/
		token = strtok( line, "," );
		strcpy( the_test_list_array[ xx ].the_c_test_name_string, token );
		remove_bad_ascii_chars( the_test_list_array[ xx ].the_c_test_name_string );

		// only remove spaces after test name comma
		remove_c_spaces( token );

        //	Get test number
		/******************************************************/
		token = strtok( NULL, "," );
		the_test_list_array[ xx ].the_test_number_double = atoi( token );
		sprintf( the_test_list_array[ xx ].the_c_test_number_string, "%s",  token );

		//	Now we need to determine the value type
		/******************************************************/
		token = strtok( NULL, "," );

		strcpy( char_33_temp, token );

        // GET LIMTS TYPE INCLUSIVE OR EXCLUSIVE
		if( strstr( char_33_temp, "><" ) || strstr( char_33_temp, "<>" ) )
		{
			if( strstr( char_33_temp, "><" ) )
			{
				the_test_list_array[ xx ].the_limits_type = INCLUSIVE;
				the_test_list_array[ xx ].the_limits_type_more = INCLUSIVE;

            }
			else if( strstr( char_33_temp, "<>" ) )
			{
				the_test_list_array[ xx ].the_limits_type = EXCLUSIVE;
 				the_test_list_array[ xx ].the_limits_type_more = EXCLUSIVE;
            }

			// extract lo limit as string
			strcpy( char_33_temp_lo, char_33_temp );
			pos = strcspn( char_33_temp_lo, "[" );
			char_33_temp_lo[ pos ] = '\0';

			// extract hi limit as string
			strcpy( char_33_temp_hi, char_33_temp );
			pos = strcspn( char_33_temp_hi, "]" );
			pos2 = strcspn( char_33_temp_hi, "," );
			char_33_temp_hi[ pos2 ] = '\0';
			memmove( &char_33_temp_hi[ 0 ], &char_33_temp_hi[ pos + 1 ], pos2 );

			// check for hex value
			if( strstr( char_33_temp_lo, "0x" ) )
			{	token = strpbrk( char_33_temp_lo, "0x" );
				the_test_list_array[ xx ].the_lo_limit_double = strtoul( token, &end, 16 );
				token = strpbrk( char_33_temp_hi, "0x" );
				the_test_list_array[ xx ].the_hi_limit_double = strtoul( token, &end, 16 );

                // create the value expected string for test list visual display
                if( the_test_list_array[ xx ].the_limits_type == INCLUSIVE )
                {
                    sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%#04X [><] %#04X",(int)the_test_list_array[ xx ].the_lo_limit_double, (int)the_test_list_array[ xx ].the_hi_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_lo_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_hi_limit_double );
                    the_test_list_array[ xx ].the_limits_type_more = INCLUSIVE;
                }

                if( the_test_list_array[ xx ].the_limits_type == EXCLUSIVE )
                {
                    sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%#04X [<>] %#04X",(int)the_test_list_array[ xx ].the_lo_limit_double, (int)the_test_list_array[ xx ].the_hi_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_lo_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_hi_limit_double );
                    the_test_list_array[ xx ].the_limits_type_more = EXCLUSIVE;
                }
			}
			// has to be a double if not hex
			else
			{	the_test_list_array[ xx ].the_lo_limit_double = strtod( char_33_temp_lo, &end );
				the_test_list_array[ xx ].the_hi_limit_double =  strtod( char_33_temp_hi, &end );

                // create the value expected string for test list visual display
                if( the_test_list_array[ xx ].the_limits_type == INCLUSIVE )
                {
                    sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%.1lf [><] %.1lf",the_test_list_array[ xx ].the_lo_limit_double, the_test_list_array[ xx ].the_hi_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%.1lf", the_test_list_array[ xx ].the_lo_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%.1lf", the_test_list_array[ xx ].the_hi_limit_double );
                    the_test_list_array[ xx ].the_limits_type_more = INCLUSIVE;
                }

                if( the_test_list_array[ xx ].the_limits_type == EXCLUSIVE )
                {
                    sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%.1lf [<>] %.1lf",the_test_list_array[ xx ].the_lo_limit_double, the_test_list_array[ xx ].the_hi_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%.1lf", the_test_list_array[ xx ].the_lo_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%.1lf", the_test_list_array[ xx ].the_hi_limit_double );
                    the_test_list_array[ xx ].the_limits_type_more = EXCLUSIVE;
                }
			}
		}

        // GET LIMTS TYPE EQUAL OR STRING
        if( strstr( char_33_temp, "=" ) || strstr( char_33_temp, "$" ) )
		{
			if( strstr( char_33_temp, "=" ) )
			{
				the_test_list_array[ xx ].the_limits_type = EQUAL;
				the_test_list_array[ xx ].the_limits_type_more = EQUAL;
            }
			else if( strstr( char_33_temp, "$" ) )
			{
				the_test_list_array[ xx ].the_limits_type = STRING_T;
				the_test_list_array[ xx ].the_limits_type_more = STRING_T;
            }

            // GET EQUAL NUMBER VALUE
            if( the_test_list_array[ xx ].the_limits_type == EQUAL )
            {
                // extract limit as string
			    strcpy( char_33_temp_hi, char_33_temp );
			    pos = strcspn( char_33_temp_hi, "=" );
			    pos2 = strcspn( char_33_temp_hi, "," );
			    char_33_temp_hi[ pos2 ] = '\0';
			    memmove( &char_33_temp_hi[ 0 ], &char_33_temp_hi[ pos + 1 ], pos2 );
 			    strncpy(char_33_temp_lo,char_33_temp_hi,32);

                // check for hex value
			    if( strstr( char_33_temp_hi, "0x" ) )
			    {	token = strpbrk( char_33_temp_hi, "0x" );
				    the_test_list_array[ xx ].the_lo_limit_double = strtoul( token, &end, 16 );
				    the_test_list_array[ xx ].the_hi_limit_double = strtoul( token, &end, 16 );
				    the_test_list_array[ xx ].the_limits_type_more = EQUAL_HEX_T;
                    sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%#04X", (int)the_test_list_array[ xx ].the_hi_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_lo_limit_double );
                    sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%#04X", (int)the_test_list_array[ xx ].the_hi_limit_double );
			    }
			    // has to be a decimal if not hex
			    else
			    {	// check for decimal point
                    if( strstr( char_33_temp_hi, "." ) )
                    {
                        the_test_list_array[ xx ].the_lo_limit_double = strtod( char_33_temp_lo, &end );
				        the_test_list_array[ xx ].the_hi_limit_double =  strtod( char_33_temp_hi, &end );
                        the_test_list_array[ xx ].the_limits_type_more = EQUAL_DOUBLE_T;
                        sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%.1lf", the_test_list_array[ xx ].the_hi_limit_double );
                        sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%.1lf", the_test_list_array[ xx ].the_hi_limit_double );
                        sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%.1lf", the_test_list_array[ xx ].the_hi_limit_double );
                    }
                    else
                    {   // non decimal
                        the_test_list_array[ xx ].the_lo_limit_double = strtol( char_33_temp_lo, &end, 10 );
				        the_test_list_array[ xx ].the_hi_limit_double = strtol( char_33_temp_hi, &end, 10 );
                        the_test_list_array[ xx ].the_limits_type_more = EQUAL_DECIMAL_T;
                        sprintf( the_test_list_array[ xx ].the_c_test_limits_string, "%d", (int)the_test_list_array[ xx ].the_hi_limit_double );
                        sprintf( the_test_list_array[ xx ].the_c_lo_limit_string, "%d", (int)the_test_list_array[ xx ].the_hi_limit_double );
                        sprintf( the_test_list_array[ xx ].the_c_hi_limit_string, "%d", (int)the_test_list_array[ xx ].the_hi_limit_double );
                    }
			    }
            }
            // GET STRING VALUE
            if( the_test_list_array[ xx ].the_limits_type == STRING_T )
            {
                // extract limit as string
			    strcpy( char_33_temp_hi, char_33_temp );
			    pos = strcspn( char_33_temp_hi, "$" );
			    pos2 = strcspn( char_33_temp_hi, "," );
			    char_33_temp_hi[ pos2 ] = '\0';
			    memmove( &char_33_temp_hi[ 0 ], &char_33_temp_hi[ pos + 1 ], pos2 );
                strcpy( the_test_list_array[ xx ].the_c_test_limits_string, char_33_temp_hi );
                the_test_list_array[ xx ].the_limits_type_more = STRING_T;
             }
        }
		//	Get test units
		/******************************************************/
		token = strtok( NULL, "," );
		strcpy( the_test_list_array[ xx ].the_c_test_units_string, token );

        // Set initial PASS / FAIL string since not been tested yet
        strcpy(  the_test_list_array[ xx ].the_c_test_measurement_string, "N / A" );
        strcpy(  the_test_list_array[ xx ].the_c_test_pass_fail_string, "N / A" );

		// clear out line buffer with null chars
		memset( line, '\0', 99 );
		++xx;

		// increment number of total tests
		++the_test_index;
	}

    int_number_of_tests = the_test_index;

    fclose(the_limits_file_fp);

    row = 0;

    // clear any previous loaded limits file
    gtk_list_store_clear(get_gtk_list_store());

    for(row = 0; row < int_number_of_tests; ++row)
    {
        iterator = get_iterator();
        gtk_list_store_append(get_gtk_list_store(), &iterator);
        // Fill fields with parsed data
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_DESCRIPTION, the_test_list_array[row].the_c_test_name_string,-1); //COL_DESCRIPTION, &color,-1);
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_NUMBER, the_test_list_array[row].the_c_test_number_string,-1); //COL_COLOR, "white",-1);
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_LIMITS, the_test_list_array[row].the_c_test_limits_string,-1);//COL_COLOR, "White",-1);
        gdk_color_parse ("yellow", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_MEASUREMENT, the_test_list_array[row].the_c_test_measurement_string,COL_COLOR, &color,-1);
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_UNITS, the_test_list_array[row].the_c_test_units_string,-1);//COL_COLOR, "White",-1);
        gdk_color_parse ("yellow", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterator,COL_PASS_FAIL, the_test_list_array[row].the_c_test_pass_fail_string,COL_COLOR, &color,-1);

    }

    test_command("Universal Test 0.1");
    test_name(filename);
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(get_progress_bar()),0);

    gtk_tree_view_columns_autosize(GTK_TREE_VIEW(get_gtk_tree_view()));
}


void remove_c_spaces(char * string )
{
    int zz;
    int yy;

	for( zz = 0; zz < (int)strlen( string ); ++zz )
	{	if( string[ zz ] == ' ' )
        {	for( yy = zz; yy < (int)strlen( string ); ++yy )
            {
                string[ yy ] = string[ yy + 1 ];
            }
        --zz;
        }
	}
 }

void remove_bad_ascii_chars( char * string )
{
    int i,j;

    for(i=0; string[i]!='\0'; ++i)
    {
        while (!((string[i]>=' ' || string[i]=='\0')))
        {
            for(j=i;string[j]!='\0';++j)
            {
                string[j]=string[j+1];
            }
            string[j]='\0';
        }
    }
 }


void test_command( char * the_command_string )
{
    g_idle_add(test_command_gui,(gpointer)the_command_string);
}

gboolean test_command_gui(gpointer user_data)
{
    char *str;

    if((strstr(user_data,"Abort")) || (strstr(user_data,"Fail")))
    {
        str = g_strdup_printf("<span foreground='red' font_desc='40.0'>%s</span>",(char*)user_data);
    }
    else if((strstr(user_data,"Pass")))
    {
        str = g_strdup_printf("<span foreground='green' font_desc='40.0'>%s</span>",(char*)user_data);
    }
    else
    {
        str = g_strdup_printf("<span foreground='white' font_desc='40.0'>%s</span>",(char*)user_data);
    }

    gtk_label_set_markup(GTK_LABEL(get_gtk_label_test_command()),str);

    g_free(str);

    return G_SOURCE_REMOVE;
}


void test_name(char * the_name_string)
{
    g_idle_add(test_name_gui,(gpointer)the_name_string);
}


gboolean test_name_gui(gpointer user_data)
{
    char *str;

    if((strstr(user_data,"Abort")) || (strstr(user_data,"Fail")))
    {
        str = g_strdup_printf("<span foreground='red' font_desc='40.0'>%s</span>",(char*)user_data);
    }
    else if((strstr(user_data,"Pass")))
    {
        str = g_strdup_printf("<span foreground='green' font_desc='40.0'>%s</span>",(char*)user_data);
    }
    else
    {
        str = g_strdup_printf("<span foreground='white' font_desc='40.0'>%s</span>",(char*)user_data);
    }

    gtk_label_set_markup(GTK_LABEL(get_gtk_label_test_name()),str);

    g_free(str);

    return G_SOURCE_REMOVE;
}


void test_data(char * the_data_string)
{
    char temp[99];

    sprintf(temp,"%s",(char*)the_data_string);

    gtk_label_set_text (GTK_LABEL (get_gtk_label_test_name()),(const char*)temp);
}

void get_single_button_text(char * the_label_string)
{
    const gchar* single_button_label;

    single_button_label = gtk_button_get_label (GTK_BUTTON(get_gtk_single_button()));
    strcpy(the_label_string,single_button_label);
}

void get_start_button_text(char * the_label_string)
{
    const gchar* start_button_label;

    start_button_label = gtk_button_get_label (GTK_BUTTON(get_gtk_start_button()));
    strcpy(the_label_string,start_button_label);
}


gboolean set_active_test_row_gui( gpointer user_data )
{
    char buf[9];

    int row = (int)user_data;

    if(get_debug_mode())
        printf("\nScroll Active test row to %d gui\n",row);

    sprintf(buf,"%d",row);

    GtkTreePath *path = gtk_tree_path_new_from_string(buf);

    gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW (get_gtk_tree_view()),path, NULL,FALSE, 0.5, 0.5);

    gtk_tree_view_set_cursor (GTK_TREE_VIEW(get_gtk_tree_view()),path,NULL,FALSE);

    gtk_tree_path_free(path);

    return G_SOURCE_REMOVE;
}


void set_active_test_row( int row )
{
    active_table_test_row = row;
    g_idle_add(set_active_test_row_gui, (gpointer)row);
}

void set_active_test_row_single( int row )
{
    active_table_test_row = row;

    if(get_debug_mode())
        printf("\nSet single active Row");
}

int get_active_test_row( void )
{
    return active_table_test_row;
}

void set_progress_bar( double value )
{
    double *ptr_value;

    g_idle_add(set_progress_bar_gui, (gpointer)ptr_value);
}

void update_progress_bar( void )
{
    if(get_debug_mode())
        printf("\nupdate_progress_bar\n");

    g_idle_add(set_progress_bar_gui, NULL);
}

gboolean set_progress_bar_gui( gpointer user_value )
{
    double  index;
    double  row;
    double  percent;

    index = (double)int_number_of_tests;
    row = (double)get_active_test_row();
    percent = (row+1) / index;

    if(get_debug_mode())
        printf("\nset_progress_bar_gui %f index - %d row - %d\n",(double)percent,index,row);

    gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(get_progress_bar()),(double)percent);

    return G_SOURCE_REMOVE;
}

char spoken_string[199];
void speak_string( char *the_string )
{
    GThread *start_speaking_string;

    // add a couple spaces for time lag for TTS engine
    sprintf(spoken_string,"  %s", the_string);

    start_speaking_string = g_thread_new("", &speak_string_gui, (gpointer)spoken_string);
}

void *speak_string_gui (gpointer user_data)
{
    changeBasePitch(10);    // 10 // 50 //changes the base pitch, accepts values within 0-100
    changeRangePitch(100);   // 50 //changes the range of pitch within the voice accepts values within 0-100, 50 is normal
    changeWordSpeed(90);   // 100 //changes word speed values should be bwtween 80 and 450

    if(get_debug_mode())
        printf("\nspeak_string_gui\n");

    speak(spoken_string);

    return NULL;
}


gboolean clear_previous_test_results_gui(gpointer user_data)
{
    int row = 0;

    // fill table with test list
    for( row = 0; row <  int_number_of_tests; ++row )
    {
        sprintf(the_test_list_array[row].the_c_test_measurement_string, "N / A" );
        update_measurement_column(row);
        sprintf(the_test_list_array[row].the_c_test_pass_fail_string, "N / A" );
        update_pass_fail_column(row);
    }

    if(get_debug_mode())
        printf("\nClear Previous Test Results GUI\n");

    set_failure( NO );

    return G_SOURCE_REMOVE;
}

void clear_previous_test_results(void)
{
    g_idle_add(clear_previous_test_results_gui,NULL);
}

void clear_previous_single_test_result( int row )
{
    sprintf(the_test_list_array[row].the_c_test_measurement_string, "N / A" );
    g_idle_add(update_measurement_column_gui, (gpointer)row);
    sprintf(the_test_list_array[row].the_c_test_pass_fail_string, "N / A" );
    g_idle_add(update_pass_fail_column_gui, (gpointer)row);
}


void *start_testing (void *data)
{
    bool    stop_testing = NO;
    char    string_buffer[ 99 ];
    int     x = 0;

    set_testing(YES);

    // GET THE NUMBER OF TESTS
    int num_tests = int_number_of_tests;

    for( x = 0; x < num_tests; x++ )
    {
        the_test_list_array[x].the_pass_fail_bool = YES;
    }

    the_test_index = 0;

    // SET THE PROGRESS BAR INDICATOR FOR THE FIRST TEST
    update_progress_bar();

    if( single_test == YES )
    {
        // table rows are zero based
        the_test_index = get_active_test_row();

            if ((double)the_test_list_array[ the_test_index ].the_test_number_double < 11000 )
            {
                test_standard(the_test_list_array[ the_test_index ].the_c_test_name_string,
                            the_test_list_array[ the_test_index ].the_test_number_double,
                            the_test_list_array[ the_test_index ].the_lo_limit_double,
                            the_test_list_array[ the_test_index ].the_hi_limit_double,
                            the_test_list_array[ the_test_index ].the_c_test_limits_string );
            }
            else
            {
                rib_standard(the_test_list_array[ the_test_index ].the_c_test_name_string,
                            the_test_list_array[ the_test_index ].the_test_number_double,
                            the_test_list_array[ the_test_index ].the_lo_limit_double,
                            the_test_list_array[ the_test_index ].the_hi_limit_double,
                            the_test_list_array[ the_test_index ].the_c_test_limits_string );
            }
    }
    else // run all tests
    {
        speak_string("Starting Tests");

        while( ( stop_testing == NO ) && ( the_test_index < num_tests ) && (if_failure() == NO)  && !check_for_abort() )
        {
            set_active_test_row( the_test_index );

            if ((double)the_test_list_array[ the_test_index ].the_test_number_double < 11000 )
            {
                test_standard(the_test_list_array[ the_test_index ].the_c_test_name_string,
                            the_test_list_array[ the_test_index ].the_test_number_double,
                            the_test_list_array[ the_test_index ].the_lo_limit_double,
                            the_test_list_array[ the_test_index ].the_hi_limit_double,
                            the_test_list_array[ the_test_index ].the_c_test_limits_string );
            }
            else
            {
                rib_standard(the_test_list_array[ the_test_index ].the_c_test_name_string,
                            the_test_list_array[ the_test_index ].the_test_number_double,
                            the_test_list_array[ the_test_index ].the_lo_limit_double,
                            the_test_list_array[ the_test_index ].the_hi_limit_double,
                            the_test_list_array[ the_test_index ].the_c_test_limits_string );
            }

            // increment next test index
            the_test_index++;
            // update progress bar
            update_progress_bar();
            // CHECK IF USER STOPPED TESTING
            stop_testing = check_for_abort();
        }
    }

    set_testing(NO);

    if( if_failure() == YES )
    {
        int failures = 0;

        for( x = 0; x < num_tests; x++ )
        {
           if( the_test_list_array[x].the_pass_fail_bool == NO )
           {
               ++failures;
           }
        }

        if( single_test == YES )
        {
            test_name( "Test Failed" );
            speak_string("Test Failed");
        }
        else
        {
            if( check_for_abort() == YES )
            {
                sprintf( string_buffer, "Testing Aborted" );
                test_name( string_buffer );
                speak_string("Testing Aborted");
            }
            else
            {
                sprintf( string_buffer, "%d Tests Failed - Test Failure", failures );
                test_name( string_buffer );
                speak_string("Test Failure");
            }
        }
    }
    else if( check_for_abort() == YES )
    {
        test_command( "Testing Aborted" );
        test_name( "Testing Aborted" );
        speak_string("Testing Aborted");
    }
    else
    {
        if( single_test == YES )
        {
            test_command( "Test Passed" );
            test_name( "Test Passed" );
            speak_string("Test Passed");
        }
        else
        {
            test_command( "All Tests Passed" );
            test_name( "All Tests Passed" );
            speak_string("All Tests Passed");
        }
    }

    set_start_button_label("Start");
    set_single_button_label("Single");

    start = NO;

    single_test = NO;

    if( if_failure() == YES )
    {

        //open_lab_jacks();

        // TURN OFF POWER
        //eDO(HandleJIG(), FIO6, (long)1 );
        //eDO(HandleJIG(), FIO4, (long)1 );
        //eDO(HandleJIG(), EIO2, (long)1 );
        //eDO(HandleJIG(), EIO3, (long)1 );
        //eDO(HandleJIG(), FIO5, (long)1 );
        //eDO(HandleJIG(), EIO0, (long)1 );

        //close_lab_jacks();

    }

    return 0;
}

void run_single_test( void )
{
    GThread *start_testing_thread;
    int         test_row = 0;
    char        char_33_temp[33];

    set_single_test_active_row();

    get_single_button_text(char_33_temp);

    if( strstr(char_33_temp, "Single" ) )
    {
        clear_abort();
        single_test = YES;
        set_failure( NO );

        set_single_button_label("STOP");

        // find which row is selected
        test_row = get_active_test_row();

        clear_previous_single_test_result( test_row );

        // spawn start testing thread
        start_testing_thread = g_thread_new("", &start_testing, NULL);
    }
    else
    {
        start = NO;
        set_abort();
        set_single_button_label("Single");
    }
}

void run_tests( void )
{
    GThread *start_testing_thread;
    char        char_33_temp[33];

    speak_string("Starting Tests");

    single_test = NO;

    get_start_button_text(char_33_temp);

    if( ( start == NO ) && strstr(char_33_temp, "Start" ) )
    {
        start = YES;
        clear_abort();
        set_failure(NO);

        if( strstr(the_test_list_array[ 0 ].the_c_test_measurement_string, "N / A") == 0 )
        {
            clear_previous_test_results();
        }

        set_start_button_label("ABORT");

        // spawn start testing thread
        start_testing_thread = g_thread_new("", &start_testing, NULL);
    }
    else
    {
        set_start_button_label("Start");
        start = NO;
        set_abort();
    }
}

bool check_for_abort( void )
{
    return do_abort;
}

void clear_abort( void )
{
    do_abort = NO;
}

void set_abort( void )
{
    do_abort = YES;
}

bool if_failure( void )
{
    return failure;
}

void set_failure( bool logic )
{
    failure = logic;
}

bool if_testing( void )
{
    return testing;
}

void set_testing( bool logic )
{
    testing = logic;
}

int selected_row_index_cb(GtkWidget *widget, gpointer data)
{
    GtkTreeSelection    *selection;
    GtkTreeModel        *model;
    GtkTreePath         *path;
    GtkTreeIter         iter;
    gint                *row;
    gchar               *path_string;

    if(single_test==YES)
    {
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(get_gtk_tree_view()));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
            path = gtk_tree_model_get_path (model, &iter);
            path_string = gtk_tree_path_to_string (path);
            row = atoi(path_string);
            set_active_test_row_single(row);

            if(get_debug_mode())
                printf("\nSelected ROW is %d\n", row);

        }
        else
        {
            g_print ("\nNo row selected.\n");
        }
    }
}

void set_single_test_active_row(void)
{
    GtkTreeSelection    *selection;
    GtkTreeModel        *model;
    GtkTreePath         *path;
    GtkTreeIter         iter;
    gint                *row;
    gchar               *path_string;

    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(get_gtk_tree_view()));
    if (gtk_tree_selection_get_selected(selection, &model, &iter))
    {
        path = gtk_tree_model_get_path (model, &iter);
        path_string = gtk_tree_path_to_string (path);
        row = atoi(path_string);
        set_active_test_row_single(row);

        if(get_debug_mode())
            printf("\nSelected ROW is %d\n", row);

    }
    else
    {   if(get_debug_mode())
            printf("\nNo row selected.\n");
    }

}

GtkTreeIter get_iter_from_row(char* row_string)
{
    GtkTreePath *path;
    GtkTreeIter iter;

    // Modify a particular row
    path = gtk_tree_path_new_from_string (row_string);
    gtk_tree_model_get_iter (GTK_TREE_MODEL (get_gtk_list_store()),&iter,path);
    gtk_tree_path_free (path);

    return iter;
}

void update_measurement_column(int index)
{
    g_idle_add(update_measurement_column_gui,(gpointer)index);
}

gboolean update_measurement_column_gui(gpointer user_data)
{
    GtkTreeIter iterr;
    int index = -1;
    char iter_string[99];
    GdkColor color;

    index = (int)user_data;
    sprintf(iter_string, "%d",index );
    iterr = get_iter_from_row(iter_string);
    gtk_list_store_set(GTK_LIST_STORE(get_gtk_list_store()), &iterr,COL_TEST_MEASUREMENT, the_test_list_array[index].the_c_test_measurement_string,-1);

    if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"PASS"))
    {
        gdk_color_parse ("green", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_MEASUREMENT, the_test_list_array[index].the_c_test_measurement_string,COL_COLOR, &color,-1);
    }
    else if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"FAIL"))
    {
        gdk_color_parse ("red", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_MEASUREMENT, the_test_list_array[index].the_c_test_measurement_string,COL_COLOR, &color,-1);
    }
    else if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"ABORT"))
    {
        gdk_color_parse ("red", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_MEASUREMENT, "ABORT",COL_COLOR, &color,-1);
    }
    else
    {
        gdk_color_parse ("yellow", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_MEASUREMENT, "N / A",COL_COLOR, &color,-1);
    }

    return G_SOURCE_REMOVE;
}


void update_pass_fail_column(int index)
{
    g_idle_add(update_pass_fail_column_gui,(gpointer)index);
}

extern GtkCellRenderer*	col_renderer_pass_fail;
gboolean update_pass_fail_column_gui(gpointer user_data)
{
    GtkTreeIter iterr;
    int index = -1;
    char iter_string[99];
    GdkColor color;

    if(get_debug_mode())
        printf("\nupdate_pass_fail_column_gui\n");

    index = (int)user_data;
    sprintf(iter_string, "%d",index );
    iterr = get_iter_from_row(iter_string);
    gtk_list_store_set(get_gtk_list_store(), &iterr,COL_TEST_PASS_FAIL, the_test_list_array[index].the_c_test_pass_fail_string,-1);

    if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"PASS"))
    {
        gdk_color_parse ("green", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_PASS_FAIL, "PASS",COL_COLOR, &color,-1);
    }
    else if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"FAIL"))
    {
        gdk_color_parse ("red", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_PASS_FAIL, "FAIL",COL_COLOR, &color,-1);
    }
    else if(strstr(the_test_list_array[index].the_c_test_pass_fail_string,"ABORT"))
    {
        gdk_color_parse ("red", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_PASS_FAIL, "FAIL",COL_COLOR, &color,-1);
    }
    else
    {
        gdk_color_parse ("yellow", &color);
        gtk_list_store_set (get_gtk_list_store(), &iterr,COL_TEST_PASS_FAIL, "N / A",COL_COLOR, &color,-1);
    }

    return G_SOURCE_REMOVE;
}


void set_start_button_label(char * the_button_string)
{
    g_idle_add(set_start_button_label_gui,(gpointer)the_button_string);
}

gboolean set_start_button_label_gui(gpointer user_data)
{
    char string[99];

    sprintf(string, "%s",(char *)user_data);

    if(get_debug_mode())
        printf("\nset_run_button_label_gui\n");

    gtk_button_set_label(GTK_BUTTON(get_gtk_start_button()),string);

    return G_SOURCE_REMOVE;
}

void set_single_button_label(char * the_button_string)
{
    g_idle_add(set_single_button_label_gui,(gpointer)the_button_string);
}

gboolean set_single_button_label_gui(gpointer user_data)
{
    char string[99];

    sprintf(string, "%s",(char *)user_data);

    if(get_debug_mode())
        printf("\nset_single_button_label_gui\n");

    gtk_button_set_label(GTK_BUTTON(get_gtk_single_button()),string);

    return G_SOURCE_REMOVE;
}

