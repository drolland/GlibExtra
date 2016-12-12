
#include <string.h>

#include "gx_csv_file.h"

typedef struct _gx_csv_file {
    GPtrArray* columns;
} GCsvFile;

void ptr_array_free_elem(gpointer data) {
    GArray* array = data;
    g_array_unref(array);
}

GCsvFile* gx_csv_file_new() {
    GCsvFile* newf = g_slice_new(GCsvFile);
    newf->columns = g_ptr_array_new_with_free_func(ptr_array_free_elem);
    return newf;
}

void gx_csv_file_free(GCsvFile* csv_file) {
    g_ptr_array_unref(csv_file->columns);
    g_slice_free(GCsvFile, csv_file);
}

void gx_csv_file_add_column(GCsvFile* csv_file, double* indices, double* values, gsize size) {

    g_assert(csv_file != NULL && indices != NULL && values != NULL && size > 0);


    GArray* indices_a = g_array_sized_new(TRUE, FALSE, sizeof (gdouble), size);
    GArray* values_a = g_array_sized_new(TRUE, FALSE, sizeof (gdouble), size);

    for (int i = 0; i < size; i++) {
        g_array_append_val(indices_a, indices[i]);
        g_array_append_val(values_a, values[i]);
    }

    g_ptr_array_add(csv_file->columns, indices_a);
    g_ptr_array_add(csv_file->columns, values_a);


}

void gx_csv_file_write_to_disk(GCsvFile* csv_file, gchar* path, gchar* gnuplot_script_path, GError** error) {

    g_assert(csv_file != NULL && path != NULL);

    GError* file_error = NULL;
    GIOChannel* file_gnuplot = NULL;

    GIOChannel* file_data = g_io_channel_new_file(path, "w", &file_error);
    if (file_error)
        goto error;


    gint nb_columns = csv_file->columns->len;

    gint max_length = 0;

    GSList* column_list = NULL;


    for (int i = 0; i < nb_columns; i++) {
        GArray* a = g_ptr_array_index(csv_file->columns, i);
        if (a->len > max_length)
            max_length = a->len;
    }


    gchar buffer[G_ASCII_DTOSTR_BUF_SIZE + 1];

    for (int i = 0; i < max_length; i++) {
        for (int j = 0; j < nb_columns; j++) {
            GArray* a = g_ptr_array_index(csv_file->columns, j);
            if (i < a->len) {
                g_ascii_dtostr(buffer, G_ASCII_DTOSTR_BUF_SIZE + 1, g_array_index(a, gdouble, i));
                g_io_channel_write_chars(file_data, buffer, -1, NULL, &file_error);
                if (file_error)
                    goto error;
            }
            g_io_channel_write_chars(file_data, ",", 1, NULL, &file_error);
            if (file_error)
                goto error;
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
