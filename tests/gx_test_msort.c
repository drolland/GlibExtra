/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./gx_merge_sort.h"
#include "./gx_qsort.h"
#include "gx_test_sort_common.h"


#define N 1000000



int main(int argc,char** argv){
    
    GTimer* timer = g_timer_new();
    
    gint* array = gx_generate_random_int_array(N);
    
    g_timer_start(timer);
    
    gx_merge_sort(array,sizeof(gint),N,cmp_func_int);
    
    g_timer_stop(timer);
    
    double seconds = g_timer_elapsed(timer,NULL);
    
    g_print("Merge sort time %f \n", seconds);
    
    g_assert(gx_is_int_array_sorted(array,N));
    
    g_free(array);
    
    array = gx_generate_random_int_array(N);
    
    g_timer_start(timer);
    
    gx_qsort_int(array,0,N-1);
    
    g_timer_stop(timer);
    
    seconds = g_timer_elapsed(timer,NULL);
    
    g_print("qsort sort time %f \n", seconds);
    
    g_assert(gx_is_int_array_sorted(array,N));
    
    g_free(array);
    
}