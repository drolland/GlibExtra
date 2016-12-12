
#include "gx_qsort.h"
#include "gx_macros.h"
#include <glib-2.0/glib.h>
#include <string.h>


#define P_DEBUG(t,l,r) if(r-l< 10) {                \
        int k = l;                                  \
        while( k <= r ){                            \
        g_printf("%d ",*((gint*)t+k++));                \
        }                                           \
        g_printf("\n");                             \
        }while(0)                                   \
     
#define P_DEBUG(t,l,r)



void gx_qsort_int(gint *t,gint l,gint r){
    
        
    if ( l == r) return;
       
    gint i = l;
    gint j = r;
     
    gint median = (r-l) / 2 + l;
    
    if ( median == 0 ){
        if ( t[i] > t[i+1] ){
            gint temp = t[i+1];
            t[i+1] = t[i];
            t[i] = temp;
        }
        return;
    }
    
    //P_DEBUG(t,l,r);
    
    GRand* rand = g_rand_new();
    gint pivot_index = g_rand_int_range(rand,l,r);
    g_rand_free(rand);
            
    gint pivot = t[pivot_index];
    t[pivot_index] = t[l];
    t[l] = pivot;
    
    
    i += 1;
    
    
    g_assert(l <= r);
    
    /* Invariant : T[l..i[ <= pivot && t]j..r] > pivot */
    
    do {

        while( t[i] <= pivot && i < j){
                i++;  
        }
        
        /* Invariant :  T[l..i[ <= pivot  && t]j..r] > pivot */
        
        
        while( t[j] > pivot && j > i){
                j--;
        }
        
        /* Invariant : ( T[l..i[ <= pivot  && t]j..r] > pivot */
        
        if ( j == i){
            break;
            // t[l..i] <= pivot && t]j..r] > pivot || t[l..i[ <= pivot && t[j..r] > pivot
        }
        else {
            gint swap = t[j];
            t[j] = t[i];
            t[i] = swap;
            
        }
       
        //  ( T[l..i] <= pivot  && t[j..r] > pivot )*/    
        
                
    } while(1);
    
    
    /* Invariant : ( T[l..i[ <= pivot  && t]j..r] > pivot && i == j*/
    
    g_assert(i == j);
    
    
    if ( t[i] > pivot){
        i--;
    } 
    else{
        j++;
    }
    
    /* T[l..i] <= pivot  && t[j..r]  > pivot*/
    
    t[l] = t[i];
    t[i] = pivot;
    --i;

    i=MAX(l,i);
    j=MIN(j,r);
  
    //P_DEBUG(t,l,r);
  
    gx_qsort_int(t,l,i);
    gx_qsort_int(t,j,r);
        
}

#define elem_index(a,e_size,i) (gchar*)(a + i * e_size)
#define elem_swap(a,e_size,x,y) do {                                            \
            memcpy(_temp_swap,elem_index(t,e_size,y),e_size);                \
            memcpy(elem_index(t,e_size,y),elem_index(t,e_size,x),e_size); \
            memcpy(elem_index(t,e_size,x),_temp_swap,e_size);                      \
            } while(0)                                                          \
            

void gx_qsort(gpointer a,size_t elem_size,gint l,gint r,GCompareFunc cmp_func){
    
        
    if ( l == r) return;
       
    gchar* t = a;
    gchar* _temp_swap = g_alloca(elem_size);
    
    gint i = l;
    gint j = r;
     
    gint median = (r-l) / 2 + l;
    
    if ( median == 0 ){
        if ( cmp_func(elem_index(t,elem_size,i),elem_index(t,elem_size,i+1)) > 0 ){
            elem_swap(t,elem_size,i,i+1);
        }
        return;
    }
    
    P_DEBUG(t,l,r);
    
    GRand* rand = g_rand_new();
    gint pivot_index = g_rand_int_range(rand,l,r);
    g_rand_free(rand);
            
    gchar* pivot = elem_index(t,elem_size,l);    
    elem_swap(t,elem_size,pivot_index,l);
    
    i += 1;
    
    
    g_assert(l <= r);
    
    /* Invariant : T[l..i[ <= pivot && t]j..r] > pivot */
    
    do {

        while( cmp_func(elem_index(t,elem_size,i),pivot) <= 0 && i < j){
                i++;  
        }
        
        /* Invariant :  T[l..i[ <= pivot  && t]j..r] > pivot */
        
        
        while( cmp_func(elem_index(t,elem_size,j),pivot) > 0 && j > i){
                j--;
        }
        
        /* Invariant : ( T[l..i[ <= pivot  && t]j..r] > pivot */
        
        if ( G_UNLIKELY(j == i)){
            break;
            // t[l..i] <= pivot && t]j..r] > pivot || t[l..i[ <= pivot && t[j..r] > pivot
        }
        else {
            elem_swap(t,elem_size,i,j);            
        }
       
        //  ( T[l..i] <= pivot  && t[j..r] > pivot )*/    
        
                
    } while(1);
    
    
    /* Invariant : ( T[l..i[ <= pivot  && t]j..r] > pivot && i == j*/
    
    g_assert(i == j);
    
    
    if ( cmp_func(elem_index(t,elem_size,i),pivot) > 0){
        i--;
    } 
    else{
        j++;
    }
    
    /* T[l..i] <= pivot  && t[j..r]  > pivot*/
    
    elem_swap(t,elem_size,i,l);
    --i;

    i=MAX(l,i);
    j=MIN(j,r);
  
    P_DEBUG(t,l,r);
  
    gx_qsort_int(a,l,i);
    gx_qsort_int(a,j,r);
        
}