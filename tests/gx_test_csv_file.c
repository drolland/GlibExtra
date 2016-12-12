/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <glib-2.0/glib.h>
#include <math.h>
#include "../gx_csv_file.h"
#include "../gx_macros.h"

#define N1 1000
#define N2 3000

void test_correct_output(){
    
    gdouble* indices1 = g_slice_alloc(N1*sizeof(double));
    gdouble* values1 = g_slice_alloc(N1*sizeof(double));
    
    for(int i = 0; i < N1; i++){
        indices1[i] = i;
        values1[i] = (i+1)*2 + i*i*i - 2 * i * i;
    }
    
    gdouble* indices2 = g_slice_alloc(N2*sizeof(double));
    gdouble* values2 = g_slice_alloc(N2*sizeof(double));
    
    for(int i = 0; i < N2; i++){
        indices2[i] = i*2;
        values2[i] = (i+1)*2 + i*i*i - 2 * i * i + 3000;
    }
    
    GCsvFile* file = gx_csv_file_new();
    
    gx_csv_file_add_column(file,indices1,values1,N1);
    gx_csv_file_add_column(file,indices2,values2,N2);
    
    gx_csv_file_write_to_disk(file,"test_csv.csv","test_csv.plot",NULL);
    
    gx_csv_file_free(file);
}

int main(int argc,char** argv){
    
    g_test_init(&argc,&argv,NULL);
    
    g_test_add_func ("/csv_file/output",test_correct_output);
    
    
   
    
    
    
    return g_test_run ();
}