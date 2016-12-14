/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "./gx_merge_sort.h"
#include "./gx_qsort.h"

gint* gx_generate_random_int_array(gsize size){
    
    GRand* rand = g_rand_new();
    
    gint* array = g_malloc(sizeof(gint)*size);
    
    for(gint i = 0;i < size;i++){
        array[i] = g_rand_int_range(rand,1,size*10);
    }
    
    return array;
}

gint gx_is_int_array_sorted(gint t[], gsize size){
    
    g_assert(t != NULL);
    
    if ( size <= 1 )
        return 1;

    for(gint i = 1; i < size;i++){
        if ( t[i] < t[i-1] )
            return 0;
    }
    return 1;    
}

#define N 1000000

int main(int argc,char** argv){
    
    GTimer* timer = g_timer_new();
    
    gint* array = gx_generate_random_int_array(N);
    
    g_timer_start(timer);
    
    gx_merge_sort(array,N);
    
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