
#include <string.h>

#include "gx_csv_file.h"

typedef struct _gx_csv_file{
    GPtrArray* columns;
}GCsvFile;


void ptr_array_free_elem(gpointer data){
    GArray* array = data;
    g_array_unref(array);
}

GCsvFile* gx_csv_file_new(){
    GCsvFile* newf = g_slice_new(GCsvFile);
    newf->columns = g_ptr_array_new_with_free_func(ptr_array_free_elem);
    return newf;
}

void gx_csv_file_free(GCsvFile* csv_file){
    g_ptr_array_unref(csv_file->columns);
    g_free(csv_file);    
}

void gx_csv_file_add_column(GCsvFile* csv_file,double* indices,double* values,gsize size){
    
    g_assert(csv_file!=NULL && indices != NULL && values != NULL && size > 0);

    
    GArray* indices_a = g_array_sized_new(TRUE,FALSE,sizeof(gdouble),size);
    GArray* values_a = g_array_sized_new(TRUE,FALSE,sizeof(gdouble),size);
    
    for(int i = 0; i< size;i++){
        g_array_append_val(indices_a,indices[i]);
        g_array_append_val(values_a,values[i]);
    }
    
    g_ptr_array_add(csv_file->columns,indices_a);
    g_ptr_array_add(csv_file->columns,values_a);

    
}

void gx_csv_file_write_to_disk(GCsvFile* csv_file, gchar* path,gchar* gnuplot_script_path,GError** error){
    
    GIOChannel* channel = g_io_channel_new_file(path,"w",NULL);
    GError* channel_error = NULL;
    
    g_assert(channel != NULL);
    
    gint nb_columns = csv_file->columns->len;
    
    gint max_length = 0;
    
    GSList* column_list = NULL;
    
    for( int i = 0; i < nb_columns;i++){
        column_list = g_slist_append(column_list,g_ptr_array_index(csv_file->columns,i));
    }
    
    for(int i = 0 ; i < nb_columns; i++){
        GArray* a = g_ptr_array_index(csv_file->columns,i);
        if ( a->len > max_length)
            max_length = a->len;
    }
    
    
    gchar buffer[G_ASCII_DTOSTR_BUF_SIZE+1];
    
    for(int i = 0; i < max_length;i++){
        for(int j = 0; j < nb_columns; j++){
            GArray* a = g_ptr_array_index(csv_file->columns,j);
            if ( i < a->len){
                g_ascii_dtostr(buffer,G_ASCII_DTOSTR_BUF_SIZE+1,g_array_index(a,gdouble,i));
                g_io_channel_write_chars(channel,buffer,-1,NULL,&channel_error);
                if ( channel_error)
                    g_propagate_error(error,channel_error);
            }
            g_io_channel_write_chars(channel,",",1,NULL,&channel_error);
            if ( channel_error)
                    g_propagate_error(error,channel_error);
        }
        g_io_channel_write_chars(channel,"\n",1,NULL,&channel_error);
        if ( channel_error)
                    g_propagate_error(error,channel_error);
    }
            
        
    g_io_channel_flush(channel,&channel_error);
    if ( channel_error)
                    g_propagate_error(error,channel_error);
    
    if ( gnuplot_script_path != NULL){
        channel = g_io_channel_new_file(gnuplot_script_path,"w",&channel_error);
        gchar buffer[256] = "set datafile separator \",\" \n";
        gchar buffer2[4096];
        g_snprintf(buffer2,4096,"plot for [i=1,%d:2] \"%s\" using i:i+1\n",nb_columns,path);
        g_io_channel_write_chars(channel,buffer,-1,NULL,&channel_error);
        if ( channel_error)
                    g_propagate_error(error,channel_error);
        g_io_channel_write_chars(channel,buffer2,-1,NULL,&channel_error);
        if ( channel_error)
                    g_propagate_error(error,channel_error);
        g_io_channel_flush(channel,&channel_error);
        if ( channel_error)
                    g_propagate_error(error,channel_error); 
    }
        
     
}
