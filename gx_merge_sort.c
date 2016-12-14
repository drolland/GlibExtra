
#include <malloc.h>
#include <string.h>

#include "gx_merge_sort.h"


void gx_merge_sort_r(gint* t, size_t n,gint* temp);


void gx_merge_sort(gint* t, size_t n){
    
    gint* temp = g_malloc(sizeof(gint) * n);
    
    gx_merge_sort_r(t,n,temp);
    
    g_free(temp);
    
}

void gx_merge_sort_r(gint* t, size_t n,gint* temp){
    
    if ( n == 1)
        return;
    
    if ( n == 2){
        if ( t[0] > t[1]){
            gint temp = t[1];
            t[1] = t[0];
            t[0] = temp;
        }
        return;
    }
    
    gint n_a = n / 2;
    gint n_b = n - n_a;
    
    gint* ta = t;
    gint* tb = t + n_a;
    
    gx_merge_sort_r(ta,n_a,temp);
    gx_merge_sort_r(tb,n_b,temp);
    
    gint* a = ta;
    gint* b = tb;
    gint* a_end = ta + n_a;
    gint* b_end = tb + n_b;
    gint* tempi = temp;

    while( a != a_end && b != b_end){
        if ( *a <= *b ){
            *temp = *a;
            a++;
        }
        else{
            *temp = *b;
            b++;
        }
        temp++;
    }
    
    gint sorted = (a-ta) + (b-tb);
             
    if ( a != a_end){
        memcpy(t+sorted,a,(a_end-a)*sizeof(gint));
    }
       
    memcpy(t,tempi,sorted * sizeof(gint));
    
}

