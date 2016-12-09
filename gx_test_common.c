#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "gx_test_common.h"



gint* gx_generate_random_int_array(gsize size){
    
    GRand* rand = g_rand_new();
    gint* array = g_malloc(sizeof(gint)*size);
    for(gint i = 0;i < size;i++){
        array[i] = g_rand_int_range(rand,0,1000);
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