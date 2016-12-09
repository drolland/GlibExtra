

#include <glib-2.0/glib.h>
#include "../gx_sort_divide.h"
#include "../gx_test_common.h"
#include "../gx_macros.h"


#define N 300
#define ITER 1000

void test_random_input(){
    
    g_test_message("Test divide and conquer sorting with random input %d N iterations",ITER);
    
     for( int k = 0; k < ITER; k++){
         
        int* t = gx_generate_random_int_array(N);
        
        gx_sort_divide_int(t,0,N-1);
        
        g_assert_true(gx_is_int_array_sorted(t,N));
        
        g_free(t);
    }
    
    g_test_message("Test divide and conquer sorting with random input successfull");
    
}



int main(int argc,char** argv){
    
    g_test_init(&argc,&argv,NULL);
    
    g_test_add_func ("/sort_divide_conquer/random_input",test_random_input);
    
    
   
    
    
    
    return g_test_run ();
}