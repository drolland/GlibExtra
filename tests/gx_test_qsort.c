

#include <glib-2.0/glib.h>
#include "../gx_qsort.h"
#include "gx_test_sort_common.h"
#include "../gx_macros.h"
#include "../gx_csv_file.h"
#include "../gx_merge_sort.h"
#include "../gx_printf.h"

#define N 1000
#define ITER 500

void test_random_input_int(){
        
     for( int k = 0; k < ITER; k++){
         
        int* t = gx_generate_random_int_array(N);
        
        gx_qsort_int(t,0,N-1);
        
        g_assert_true(gx_is_int_array_sorted(t,N));
        
        g_free(t);
    }
    
}

void test_random_input_generic(){
    
    for( int k = 0; k < ITER; k++){
         
        gint* t = gx_generate_random_int_array(N);
        
        gx_qsort(t,sizeof(gint),0,N-1,cmp_func_int);
        
        g_assert_true(gx_is_int_array_sorted(t,N));
        
        g_free(t);
    }
}

void test_constant_input_generic(){
    
    for( int k = 0; k < 1; k++){
         
        gint* t = gx_generate_constant_array(N);
        
        gx_qsort(t,sizeof(gint),0,N-1,cmp_func_int);
        
        g_assert_true(gx_is_int_array_sorted(t,N));
        
        g_free(t);
    }
}

int main(int argc,char** argv){
    
    g_test_init(&argc,&argv,NULL);
    
    gx_printf_c(BLUE,"Test gx_test_qsort started\n");
    
    g_test_add_func ("/qsort/random_input",test_random_input_int);
    g_test_add_func ("/qsort/random_input_generic",test_random_input_generic);
    g_test_add_func ("/qsort/constant_input_generic",test_constant_input_generic);

    return g_test_run ();
}