#include <pigpio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <sys/mman.h>
//#include <espeak/speak_lib.h>
#include <espeak-ng/speak_lib.h>

#include "headers/TestModel.h"
#include "headers/TTspeech.h"
#include "headers/pi_relay_output.h"
#include "headers/espeak_ng.h"
#include "headers/audio.h"


GtkWidget*			main_window;
GtkWidget*			gtk_fixed;

GtkWidget*          gtk_label_test_name;
GtkLabel*           gtk_label_test_command;

GtkWidget*          gtk_menu;
GtkWidget*			gtk_start_button;
GtkWidget*          gtk_single_button;
GtkWidget*          gtk_test_command;
GtkWidget*          gtk_layout;

GtkEventBox*        event_box_command;
GtkEventBox*        event_box_name;


GtkProgressBar*     progress_bar;

GtkListStore*		gtk_list_store;

GtkTreeView*		gtk_tree_view;

GtkTreeViewColumn*	col_test_description;
GtkTreeViewColumn*	col_test_number;
GtkTreeViewColumn*	col_test_limits;
GtkTreeViewColumn*	col_test_measurement;
GtkTreeViewColumn*	col_test_units;
GtkTreeViewColumn*	col_test_pass_fail;
GtkTreeViewColumn*	color_col;


GtkTreeSelection*	row_select;

GtkCellRenderer*	col_renderer_description;
GtkCellRenderer*	col_renderer_number;
GtkCellRenderer*	col_renderer_limits;
GtkCellRenderer*	col_renderer_measurement;
GtkCellRenderer*	col_renderer_units;
GtkCellRenderer*	col_renderer_pass_fail;
GtkCellRenderer*    color_renderer;

GtkTreeIter iter;	// iterators

GtkBuilder*			builder;

GdkColor color;
int debug = 0;


void on_main_window_destroy();
void start_button_clicked_cb();


////
espeak_POSITION_TYPE position_type;
espeak_AUDIO_OUTPUT output;
char *path = NULL;
int buflength = 512, options = 0;
void* user_data;

GThread *audio_testing_thread;


unsigned int size, position = 0, end_position = 0, flags = 0, *unique_identifier;

/* This is simple example, how to call espeak-ng API from C program.
 * It should be compiled by passing reference to registered library of espeak-ng, e.g.:
 * gcc speak.c -lespeak-ng -o speak
 */
////

int main(int argc, char* argv[])
{
 	gtk_init(&argc, &argv);     // init Gtk

	builder =                   gtk_builder_new_from_file("main_windowEventBoxColor.glade");                         // grab xml UI glade file

	main_window =               GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));                     // add main window to builder
    // add the gui items to the main window
	event_box_command =         GTK_EVENT_BOX(gtk_builder_get_object(builder, "event_box_command"));            // add event box for test command to builder
	event_box_name =            GTK_EVENT_BOX(gtk_builder_get_object(builder, "event_box_name"));               // add event bok for test name to builder

	gtk_label_test_command =    GTK_LABEL(gtk_builder_get_object(builder, "test_command"));                     // add test command label to builder
	gtk_label_test_name =       GTK_WIDGET(gtk_builder_get_object(builder, "test_name"));                       // add test name label to builder

	gtk_fixed =				    GTK_WIDGET(gtk_builder_get_object(builder, "gtk_fixed"));
	gtk_layout =			    GTK_WIDGET(gtk_builder_get_object(builder, "gtk_layout"));

	progress_bar =			    GTK_PROGRESS_BAR(gtk_builder_get_object(builder, "progress_bar"));
	gtk_list_store =			GTK_LIST_STORE(gtk_builder_get_object(builder, "gtk_list_store"));
	gtk_tree_view =	            GTK_TREE_VIEW(gtk_builder_get_object(builder, "gtk_tree_view"));

	col_test_description =	    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_description"));	// col 0
	col_test_number =		    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_number"));		// col 1
	col_test_limits =		    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_limits"));		// col 2
	col_test_measurement =	    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_measurement"));	// col 3
	col_test_units =		    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_units"));		// col 4
	col_test_pass_fail =	    GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "col_test_pass_fail"));	// col 5
	//color_col =	                GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "color_col"));	// col 5


	col_renderer_description =	GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_description")); // col 0 renderer
	col_renderer_number =		GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_number"));		// col 1 renderer
	col_renderer_limits =		GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_limits"));		// col 2 renderer
	col_renderer_measurement =	GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_measurement")); // col 3 renderer
	col_renderer_units =		GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_units"));		// col 4 renderer
	col_renderer_pass_fail =	GTK_CELL_RENDERER(gtk_builder_get_object(builder, "col_renderer_pass_fail"));	// col 5 renderer
	//color_renderer =	        GTK_CELL_RENDERER(gtk_builder_get_object(builder, "color_renderer"));	// col 5 renderer
	//color_renderer =            gtk_cell_renderer_text_new ();

	row_select =                GTK_TREE_SELECTION(gtk_builder_get_object(builder, "row_select"));              // tree view selection

	gtk_tree_view_column_add_attribute(col_test_description, col_renderer_description, "text", (gint)COL_DESCRIPTION);        // attach the renderer to the column
	gtk_tree_view_column_add_attribute(col_test_number, col_renderer_number, "text", (gint)COL_NUMBER);			        // attach the renderer to the column
	gtk_tree_view_column_add_attribute(col_test_limits, col_renderer_limits, "text", (gint)COL_LIMITS);			        // attach the renderer to the column
	//gtk_tree_view_column_add_attribute(col_test_measurement, col_renderer_measurement, "text", (gint)COL_MEASUREMENT);        // attach the renderer to the column
	gtk_tree_view_column_add_attribute(col_test_units, col_renderer_units, "text", (gint)COL_UNITS);				    // attach the renderer to the column
	//gtk_tree_view_column_add_attribute(col_test_pass_fail, col_renderer_pass_fail, "text", (gint)COL_COLOR);		    // attach the renderer to the column

	g_object_set(col_renderer_description, "foreground", "white", "foreground-set", TRUE, NULL);
	g_object_set(col_renderer_description, "background", "black", "background-set", TRUE, NULL);

	g_object_set(col_renderer_number, "foreground", "white", "foreground-set", TRUE, NULL);
	g_object_set(col_renderer_number, "background", "black", "background-set", TRUE, NULL);

	g_object_set(col_renderer_limits, "foreground", "white", "foreground-set", TRUE, NULL);
	g_object_set(col_renderer_limits, "background", "black", "background-set", TRUE, NULL);

	g_object_set(col_renderer_measurement, "background", "black", "background-set", TRUE, NULL);

	g_object_set(col_renderer_units, "foreground", "white", "foreground-set", TRUE, NULL);
	g_object_set(col_renderer_units, "background", "black", "background-set", TRUE, NULL);

	g_object_set(col_renderer_pass_fail, "background", "black", "background-set", TRUE, NULL);


	//gtk_tree_view_column_add_attribute(color_col, color_renderer, "text", (gint)COL_COLOR);		    // attach the renderer to the column
    //color_renderer = gtk_tree_view_column_new_with_attributes ("color",color_renderer,"text", COL_PASS_FAIL,"foreground", COL_COLOR,NULL);



    //gtk_tree_view_column_set_fixed_width (color_col,0);

    //gtk_tree_view_column_set_max_width (color_col, 0);



	row_select = gtk_tree_view_get_selection(GTK_TREE_VIEW(gtk_tree_view));
    gtk_tree_selection_set_mode (row_select, GTK_SELECTION_SINGLE);

	gtk_builder_connect_signals(builder, NULL);

	gtk_start_button =  GTK_WIDGET(gtk_builder_get_object(builder,"start_button"));
	gtk_single_button = GTK_WIDGET(gtk_builder_get_object(builder,"single_button"));
	gtk_menu =          GTK_WIDGET(gtk_builder_get_object(builder,"gtk_file_menu_item"));
    gtk_progress_bar_set_fraction (progress_bar,1);

	g_object_unref(builder);

    //gtk_label_set_text(GTK_LABEL(gtk_label_test_command),(const char *)"Universal Test 0.1");
    test_command("Universal Test 0.1");


    gdk_color_parse ("black", &color);
    gtk_widget_modify_bg ( GTK_EVENT_BOX(event_box_command), GTK_STATE_NORMAL, &color);
    gtk_widget_modify_bg ( GTK_EVENT_BOX(event_box_name), GTK_STATE_NORMAL, &color);

	gtk_widget_show_all(main_window);

    speakInit();

    if(init_relay_bank())
    {
        test_command("pigpio initialisation failed");
    }

	// run main GUI thread
	gtk_main();

 	return EXIT_SUCCESS;
}

void on_main_window_destroy(GtkWidget *widget, gpointer data)
{
    // fix me speakCleanup();

    // This function resets the used DMA channels, releases memory, and
    // terminates any running threads.
    gpioTerminate();

    espeak_Terminate();

    system("killall omxplayer.bin");

    gtk_main_quit();
}

void start_button_clicked_cb(GtkWidget *widget, gpointer data)
{
    if(get_debug_mode())
        printf("\nStart Button Pressed\n");

        run_tests();
}

void single_button_clicked_cb(GtkWidget *widget, gpointer data)
{
    if(get_debug_mode())
        printf("\nSingle Button Pressed\n");

    run_single_test();
}

void debug_cb(GtkWidget *widget, gpointer data)
{
    if(get_debug_mode() == TRUE)
    {
        set_debug_mode(FALSE);
        printf("\nDebug Mode Turned OFF for Printfs\n");
    }
    else
    {
        set_debug_mode(TRUE);
        printf("\nDebug Mode Turned ON for Printfs\n");
    }
}

int get_debug_mode(void)
{
    return debug;
}

void set_debug_mode(int value)
{
    debug = value;
}

GtkListStore* get_gtk_list_store( void )
{
    return gtk_list_store;
}

GtkProgressBar* get_progress_bar( void )
{
    return progress_bar;
}

GtkTreeView* get_gtk_tree_view( void )
{
    return gtk_tree_view;
}

GtkLabel* get_gtk_label_test_command( void )
{
    return gtk_label_test_command;
}

GtkWidget* get_gtk_label_test_name( void )
{
    return gtk_label_test_name;
}

GtkWidget* get_gtk_single_button( void )
{
    return gtk_single_button;
}

GtkWidget* get_gtk_start_button( void )
{
    return gtk_start_button;
}

GtkTreeIter get_iterator( void )
{
    return iter;
}
