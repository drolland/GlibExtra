/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gx_plot.h
 * Author: drolland
 *
 * Created on 9 décembre 2016, 12:20
 */

#ifndef GX_PLOT_H
#define GX_PLOT_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS
        
typedef struct _gx_csv_file GCsvFile;


GCsvFile* gx_csv_file_new();

void gx_csv_file_free(GCsvFile* cvs_file);

void gx_csv_file_add_column(GCsvFile* csv_file,double* indices,double* values,gsize size);

void gx_csv_file_write_to_disk(GCsvFile* csv_file,gchar* path,gchar* gnuplot_script_path,GError** error);        
        
G_END_DECLS

#endif /* GX_PLOT_H */

