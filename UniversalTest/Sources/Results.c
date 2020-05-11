#include "../headers/TestModel.h"
#include "../headers/TestStandard.h"

extern struct test_list_data_struct the_test_list_array[199];


void result_number( double measurement )
{
    double  lo_limit;
    double  hi_limit;
    int     the_test_index = 0;

    // table rows are 0 based
    the_test_index = get_active_test_row();

    lo_limit = the_test_list_array[the_test_index].the_lo_limit_double;
    hi_limit = the_test_list_array[the_test_index].the_hi_limit_double;


    if( the_test_list_array[the_test_index].the_limits_type == INCLUSIVE )
    {
        // CHECK FOR FAILURE        ><  i.e.    1 >= measurement <= 5
        if( the_test_list_array[the_test_index].the_lo_limit_double <= measurement &&
            the_test_list_array[the_test_index].the_hi_limit_double >= measurement )
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = YES;
        }
        else
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = NO;
        }
    }
    else if( the_test_list_array[the_test_index].the_limits_type == EXCLUSIVE )
    {
        // CHECK FOR FAILURE        <>  i.e.    measurement <= 1 || measurement >= 5
        if( measurement <= the_test_list_array[the_test_index].the_lo_limit_double ||
            measurement >= the_test_list_array[the_test_index].the_hi_limit_double )
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = YES;
        }
        else
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = NO;
        }
    }
    else if( the_test_list_array[the_test_index].the_limits_type == EQUAL )
    {
        // CHECK FOR FAILURE        =  i.e. measurement == 5
        if( measurement == the_test_list_array[the_test_index].the_lo_limit_double )
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = YES;
        }
        else
        {
            the_test_list_array[the_test_index].the_pass_fail_bool = NO;
        }
    }

    // format string measurement per limit type
    if( the_test_list_array[the_test_index].the_limits_type_more == EQUAL_DOUBLE_T)
    {
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%.1lf", measurement );
    }
    if( the_test_list_array[the_test_index].the_limits_type_more == EQUAL_DECIMAL_T)
    {
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%d", (int)measurement );
    }
    if( the_test_list_array[the_test_index].the_limits_type_more == EQUAL_HEX_T)
    {
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%#04X", (int)measurement );
    }
    if( the_test_list_array[the_test_index].the_limits_type_more == INCLUSIVE)
    {
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%.1lf", measurement );
    }
    if( the_test_list_array[the_test_index].the_limits_type_more == EXCLUSIVE)
    {
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%.1lf", measurement );
    }


    if( check_for_abort() == YES )
    {
        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "ABORT" );
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%s", "ABORT" );
        test_name(the_test_list_array[the_test_index].the_c_test_pass_fail_string);
        test_name("ABORT");

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);

        //set_failure( YES );
    }
    else if( the_test_list_array[the_test_index].the_pass_fail_bool == YES )
    {
        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "PASS" );
        test_name(the_test_list_array[the_test_index].the_c_test_pass_fail_string);
        test_name("PASS");

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);
    }
    else
    {
        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "FAIL" );
        test_name(the_test_list_array[the_test_index].the_c_test_pass_fail_string);
        test_name("FAIL");

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);

        set_failure( YES );

    }
}

void result_string( char * string_measurement )
{
    int     the_test_index = 0;

    // table rows are zero based indexes
    the_test_index = get_active_test_row();

    if( strcmp( string_measurement, the_test_list_array[the_test_index].the_c_test_limits_string ) == 0 )
    {
        the_test_list_array[the_test_index].the_pass_fail_bool = YES;

        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "PASS" );
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%s", string_measurement );
        test_name("PASS");

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);
    }
    else
    {
        the_test_list_array[the_test_index].the_pass_fail_bool = NO;

        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "FAIL" );
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%s", string_measurement );

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);

        set_failure( YES );
    }

    if( check_for_abort() == YES )
    {
        // update active table row cells to red if aborted
        sprintf(the_test_list_array[the_test_index].the_c_test_pass_fail_string, "%s", "ABORT" );
        sprintf(the_test_list_array[the_test_index].the_c_test_measurement_string, "%s", "ABORT" );
        test_name(the_test_list_array[the_test_index].the_c_test_pass_fail_string);
        test_name("ABORT");

        // update measurement in list store
        update_measurement_column(the_test_index);
        update_pass_fail_column(the_test_index);
    }

}

