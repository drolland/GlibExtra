/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#ifndef GX_TEST_SORT_COMMON_H
#define GX_TEST_SORT_COMMON_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS
        

gint* gx_generate_random_int_array(gsize size){
    
    GRand* rand = g_rand_new();
    
    gint* array = g_malloc(sizeof(gint)*size);
    
    for(gint i = 0;i < size;i++){
        array[i] = g_rand_int_range(rand,1,size*2);
    }
    
    g_rand_free(rand);
    
    return array;
}

gint* gx_generate_constant_array(gsize size){
    
    
    gint* array = g_malloc(sizeof(gint)*size);
    
    for(gint i = 0;i < size;i++){
        array[i] = 4;
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

gint cmp_func_int_merge(gconstpointer a,gconstpointer b){
    return *(gint*)a - *(gint*)b;
}

gint cmp_func_int(gconstpointer a,gconstpointer b){
    return *((gint*)a) - *((gint*)b);
}

gint cmp_func_int_data(gconstpointer a,gconstpointer b,gpointer data){
    return *((gint*)a) - *((gint*)b);
}

G_END_DECLS

#endif 

