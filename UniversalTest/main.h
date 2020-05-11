#include <gtk/gtk.h>

GtkListStore*   get_gtk_list_store( void );
GtkProgressBar* get_progress_bar( void );
GtkTreeView*    get_gtk_tree_view( void );
GtkLabel*       get_gtk_label_test_command( void );
GtkWidget*      get_gtk_label_test_name( void );
GtkWidget*      get_gtk_single_button( void );
GtkWidget*      get_gtk_start_button( void );
GtkTreeIter     get_iterator( void );

int get_debug_mode(void);
void set_debug_mode(int value);
