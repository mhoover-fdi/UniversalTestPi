#include <gtk/gtk.h>
#include <stdbool.h>


#define INCLUSIVE           0
#define EXCLUSIVE           1
#define EQUAL               2
#define STRING_T            3
#define EQUAL_DOUBLE_T      5
#define EQUAL_DECIMAL_T     6
#define EQUAL_HEX_T         7


#define COL_TEST_NAME           0
#define COL_TEST_NUMBER         1
#define COL_TEST_LIMITS         2
#define COL_TEST_MEASUREMENT    3
#define COL_TEST_UNITS          4
#define COL_TEST_PASS_FAIL      5

enum
{
    COL_DESCRIPTION = 0,
    COL_NUMBER,
    COL_LIMITS,
    COL_MEASUREMENT,
    COL_UNITS,
    COL_PASS_FAIL,
    COL_COLOR,
    NUM_COLS
};

#define YES                     1
#define NO                      0

struct test_list_data_struct
{
    char    the_c_test_name_string[133];
    char    the_c_test_number_string[99];
    char    the_c_test_limits_string[99];
    char    the_c_lo_limit_string[99];
    char    the_c_hi_limit_string[99];
    char    the_c_test_measurement_string[99];
    char    the_c_test_units_string[99];
    char    the_c_test_pass_fail_string[99];

    double  the_test_number_double;
    double  the_lo_limit_double;
    double  the_hi_limit_double;
    double  the_test_measurement_double;
    bool    the_pass_fail_bool;

    int     the_limits_type;
    int     the_limits_type_more;
};

bool check_for_abort( void );
void result_number( double measurement );
void result_string( char * string );
void clear_old_test_results( void );
bool if_testing( void );
bool if_failure( void );
void set_testing( bool logic );
void set_failure(bool logic );
bool check_for_single_test( void );
void clear_abort( void );

#define	MAX_TESTS	1200				// maximum number of tests per/product

void open_limits_file(GtkWidget *widget, gpointer data);
void remove_c_spaces(char * string );
void remove_bad_ascii_chars( char * string );
void test_command( char * the_command_string );
gboolean test_command_gui(gpointer user_data);
void test_name(char * the_name_string);
gboolean test_name_gui(gpointer user_data);
void test_data(char * the_data_string);
void get_single_button_text(char * the_label_string);
void get_start_button_text(char * the_label_string);
gboolean set_active_test_row_gui( gpointer user_data );
void set_active_test_row_single( int row );
int get_active_test_row( void );
int get_main_win( void );
int get_dmm_win( void );
void set_progress_bar( double value );
gboolean set_progress_bar_gui( gpointer user_value );
void update_progress_bar( void );
void *speak_string_gui (gpointer user_data);
void speak_string( char *string );
void clear_previous_test_results( void );
gboolean clear_previous_test_results_gui(gpointer user_data);
void clear_previous_single_test_result( int row );
void *start_testing(void *data);
void run_single_test( void );
void run_tests( void );

bool check_for_abort( void );
bool if_failure( void );
void set_failure( bool logic );
void clear_abort( void );
void set_abort( void );

int selected_row_index_cb(GtkWidget *widget, gpointer data);
gboolean set_active_test_rowz_gui(gpointer user_data);
void set_single_test_active_row(void);
void on_row_changed_cb(GtkWidget *widget, gpointer label);
GtkTreeIter get_iter_from_row(char* row_string);

void update_measurement_column(int index);
gboolean update_measurement_column_gui(gpointer data);
void update_pass_fail_column(int index);
gboolean update_pass_fail_column_gui(gpointer data);

void set_start_button_label(char * the_button_string);
void set_single_button_label(char * the_button_string);
gboolean set_start_button_label_gui(gpointer user_data);
gboolean set_single_button_label_gui(gpointer user_data);

void cell_data_func1(GtkTreeViewColumn *column,GtkCellRenderer *renderer, GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data);
void cell_data_fail(GtkTreeViewColumn *column,GtkCellRenderer *renderer, GtkTreeModel *model,GtkTreeIter *iter,gpointer user_data);
void cell_colourer (GtkTreeViewColumn *col, GtkCellRenderer *cell, GtkTreeModel *model, GtkTreeIter *iter, gpointer user_data);

void *audio_output_thread(void *data);
