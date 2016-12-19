
#include <string.h>


#include "gx_csv_file.h"

typedef struct _gx_csv_file {
    GPtrArray* columns;
    guint ref;
} GCsvFile;

typedef struct _column {
    GArray* array;
    gchar* name;
} _Column ;



void ptr_array_free_elem(gpointer data) {
    _Column* column = data;
    g_array_unref(column->array);
    if ( column->name )
     g_free(column->name);
    g_free(column);
}

void ptr_array_free_elem_string(gpointer data) {
    char* str = data;
    g_free(str);
}

GCsvFile* gx_csv_file_new() {
    GCsvFile* newf = g_slice_new(GCsvFile);
    newf->columns = g_ptr_array_new_with_free_func(ptr_array_free_elem);
    newf->ref = 1;
    return newf;
}

void gx_csv_file_ref(GCsvFile* csv_file) {
    g_assert(csv_file != NULL);
    csv_file->ref++;
}

void gx_csv_file_unref(GCsvFile* csv_file) {
    g_assert(csv_file != NULL);
    csv_file->ref--;
    if ( csv_file->ref <= 0){
        g_ptr_array_unref(csv_file->columns);
        g_slice_free(GCsvFile, csv_file);
    }
}

void gx_csv_file_add_column(GCsvFile* csv_file,gdouble* values,gsize size,gchar* name) {

    g_assert(csv_file != NULL &&  values != NULL && size > 0);

    
    GArray* values_a = g_array_sized_new(TRUE, FALSE, sizeof (gdouble), size);

    for (int i = 0; i < size; i++) {
        g_array_append_val(values_a, values[i]);
    }

    _Column* column = g_malloc(sizeof(_Column*));
    column->array = values_a;
    column->name = g_strdup(name);
    
    g_ptr_array_add(csv_file->columns, column);
    
}

void gx_csv_file_write_to_disk(GCsvFile* csv_file, gchar* path, gchar* gnuplot_script_path, GError** error) {

    g_assert(csv_file != NULL && path != NULL);

    GError* file_error = NULL;
    GIOChannel* file_gnuplot = NULL;
    GIOChannel* file_data = NULL;
    
    file_data = g_io_channel_new_file(path, "w", &file_error);
    
    if (file_error)
        goto error;


    gint nb_columns = csv_file->columns->len;

    gint max_length = 0;

    GSList* column_list = NULL;


    for (int i = 0; i < nb_columns; i++) {
        _Column* c = g_ptr_array_index(csv_file->columns,i);
        GArray* a = c->array;
        if (a->len > max_length)
            max_length = a->len;
    }

    /* Write csv file header*/
    
    
    
    
    /* Write csv file column title headers*/
    for(int i = 0; i < nb_columns ; i++){
        
        _Column* c = g_ptr_array_index(csv_file->columns,i);
        
        if ( c->name != NULL)
            g_io_channel_write_chars(file_data,c->name,strlen(c->name),NULL,&file_error);
        
        if (file_error)
                goto error;
        
        if ( i < nb_columns - 1){
            
            g_io_channel_write_chars(file_data, ",", 1, NULL, &file_error);
        
            if (file_error)
                goto error;
            
        }
    }
    
    g_io_channel_write_chars(file_data, "\n", 1, NULL, &file_error);
        
        if (file_error)
            goto error;
        

    gchar buffer[G_ASCII_DTOSTR_BUF_SIZE + 1];

    for (int i = 0; i < max_length; i++) {
        
        for (int j = 0; j < nb_columns; j++) {
           
            _Column* c = g_ptr_array_index(csv_file->columns,j);
            GArray* a = c->array;
            
            if (i < a->len) {
                
                g_ascii_dtostr(buffer, G_ASCII_DTOSTR_BUF_SIZE + 1, g_array_index(a, gdouble, i));
                
                g_io_channel_write_chars(file_data, buffer, -1, NULL, &file_error);
                
                if (file_error)
                    goto error;
            }
            
            if ( j < nb_columns - 1){
            
                g_io_channel_write_chars(file_data, ",", 1, NULL, &file_error);
            
                if (file_error)
                    goto error;
            }
        }
        
        g_io_channel_write_chars(file_data, "\n", 1, NULL, &file_error);
        
        if (file_error)
            goto error;
    }

    g_io_channel_flush(file_data, &file_error);
    if (file_error)
        goto error;

    if (gnuplot_script_path != NULL) {

        file_gnuplot = g_io_channel_new_file(gnuplot_script_path, "w", &file_error);
        if (file_error)
            goto error;

        gchar buffer[256] = "set datafile separator \",\" \n";
        gchar buffer2[4096];
        g_snprintf(buffer2, 4096, "plot for [i=1:%d:2] \"%s\" using i:i+1\n", nb_columns, path);

        g_io_channel_write_chars(file_gnuplot, buffer, -1, NULL, &file_error);
        if (file_error)
            goto error;

        g_io_channel_write_chars(file_gnuplot, buffer2, -1, NULL, &file_error);
        if (file_error)
            goto error;

        g_io_channel_flush(file_gnuplot, &file_error);
        if (file_error)
            goto error;
    }

error:

    if (file_data)
        g_io_channel_unref(file_data);
    if (file_gnuplot)
        g_io_channel_unref(file_gnuplot);
    if (file_error)
        g_propagate_error(error, file_error);

}
