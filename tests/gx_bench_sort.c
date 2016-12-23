

#include <glib-2.0/glib.h>
#include "../gx_qsort.h"
#include "gx_test_sort_common.h"
#include "../gx_macros.h"
#include "../gx_csv_file.h"
#include "../gx_merge_sort.h"

#define MAX_N 10000
#define STEP_N 200
#define ITER_N 50

void plot_complexity(){
    
    gdouble* indices = g_malloc(1000*sizeof(double));
    gdouble* values = g_malloc(1000*sizeof(double));
    gdouble* indices2 = g_malloc(1000*sizeof(double));
    gdouble* values2 = g_malloc(1000*sizeof(double));
    gdouble* indices3 = g_malloc(1000*sizeof(double));
    gdouble* values3 = g_malloc(1000*sizeof(double));
    gdouble* indices4 = g_malloc(1000*sizeof(double));
    gdouble* values4 = g_malloc(1000*sizeof(double));
    gint i = 0;
    
    GTimer* timer = g_timer_new();
    GTimer* timer2 = g_timer_new();
    GTimer* timer3 = g_timer_new();
    GTimer* timer4 = g_timer_new();
    g_timer_start(timer);
    g_timer_stop(timer);
    g_timer_start(timer2);
    g_timer_stop(timer2);
    g_timer_start(timer3);
    g_timer_stop(timer3);
    g_timer_start(timer4);
    g_timer_stop(timer4);
    
     for( int n = STEP_N; n < MAX_N;  n += STEP_N){
        
         g_timer_reset(timer);
         g_timer_reset(timer2);  
         g_timer_reset(timer3);
         g_timer_reset(timer4);
         
         for (int k = 0; k < ITER_N; k++){
             
            gint* t = gx_generate_random_int_array(n);
        
            g_timer_continue(timer);
        
            gx_qsort_int(t,0,n-1);
            
            g_timer_stop(timer);

            g_free(t);
            
            t = gx_generate_random_int_array(n);
        
            g_timer_continue(timer2);
        
            g_qsort_with_data(t,n,sizeof(gint),cmp_func_int_data,NULL);
            
            g_timer_stop(timer2);

            g_free(t);
            
            t = gx_generate_random_int_array(n);
        
            g_timer_continue(timer3);
        
            gx_merge_sort(t,n);
            
            g_timer_stop(timer3);

            g_free(t);
            
            t = gx_generate_random_int_array(n);
            
            g_timer_continue(timer4);
        
            gx_qsort(t,sizeof(gint),0,n-1,cmp_func_int);
            
            g_timer_stop(timer4);

            g_free(t);
         }
        
         indices[i] = (gdouble)n;
         values[i] = g_timer_elapsed(timer,NULL);
         indices2[i] = (gdouble)n;
         values2[i] = g_timer_elapsed(timer2,NULL);
         indices3[i] = (gdouble)n;
         values3[i] = g_timer_elapsed(timer3,NULL);
         indices4[i] = (gdouble)n;
         values4[i] = g_timer_elapsed(timer4,NULL);
         i++;
        
    }
    
    
    
    GCsvFile* file = gx_csv_file_new();
    
    gx_csv_file_add_column(file,indices,MAX_N/STEP_N - 1,"_");
    gx_csv_file_add_column(file,values,MAX_N/STEP_N - 1,"gx_qsort_int");
    gx_csv_file_add_column(file,indices2,MAX_N/STEP_N - 1,"_");
    gx_csv_file_add_column(file,values2,MAX_N/STEP_N - 1,"g_qsort_with_data");
    gx_csv_file_add_column(file,indices3,MAX_N/STEP_N - 1,"_");
    gx_csv_file_add_column(file,values3,MAX_N/STEP_N - 1,"gx_merge_sort");
    gx_csv_file_add_column(file,indices4,MAX_N/STEP_N - 1,"_");
    gx_csv_file_add_column(file,values4,MAX_N/STEP_N - 1,"gx_qsort");
    
    GError* error = NULL;
    
    gx_csv_file_write_to_disk(file,"tests/bench_sort.csv","tests/bench_sort.plot",&error);
        
    g_assert_no_error(error);
    
    g_timer_destroy(timer);
    
    g_free(indices);
    
    g_free(values);
    
    gx_csv_file_unref(file);
        
}


int main(int argc,char** argv){
    
    g_test_init(&argc,&argv,NULL);
    
    g_test_add_func ("/bench_sort/plot_complexity",plot_complexity);
   
    
    
    
    return g_test_run ();
}
