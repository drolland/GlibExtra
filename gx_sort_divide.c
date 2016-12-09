
#include "gx_sort_divide.h"
#include "gx_macros.h"
#include <glib-2.0/glib.h>


#define P_DEBUG(t,l,r) if(r-l< 10) {                \
        int k = l;                                  \
        while( k <= r ){                            \
        g_printf("%d ",t[k++]);                     \
        }                                           \
        g_printf("\n");                             \
        }while(0)                                   \
     
#define P_DEBUG(t,l,r)

gint call = 0;

void gx_sort_divide_int(gint *t,gint l,gint r){
    
        
    if ( l == r) return;
    
    call++;
    
    
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
    
    P_DEBUG(t,l,r);
    
    gint pivot = t[median];
    t[median] = t[l];
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
  
    P_DEBUG(t,l,r);
  
    gx_sort_divide_int(t,l,i);
    gx_sort_divide_int(t,j,r);
        
}
