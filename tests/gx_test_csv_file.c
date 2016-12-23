/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <glib-2.0/glib.h>
#include <math.h>
#include <malloc.h>
#include "../gx_csv_file.h"
#include "../gx_macros.h"
#include "../gx_printf.h"

#define N1 1000
#define N2 3000

void test_correct_behaviour() {

    gchar* produced_file_content = NULL;
    gchar* reference_file_content = NULL;

    struct mallinfo memory_info_begin = mallinfo();


    /* Write data */

    gdouble* indices1 = g_malloc(N1 * sizeof (double));
    gdouble* values1 = g_malloc(N1 * sizeof (double));

    
    for (int i = 0; i < N1; i++) {
        indices1[i] = i;
        values1[i] = (i + 1)*2 + i * i * i - 2 * i * i;
    }


    gdouble* indices2 = g_malloc(N2 * sizeof (double));
    gdouble* values2 = g_malloc(N2 * sizeof (double));

    for (int i = 0; i < N2; i++) {
        indices2[i] = i * 2;
        values2[i] = (i + 1)*2 + i * i * i - 2 * i * i + 3000;
    }

    GCsvFile* file = gx_csv_file_new();

    gx_csv_file_add_column(file, indices1, N1, "I1");
    gx_csv_file_add_column(file, values1,  N1, "V1");
    gx_csv_file_add_column(file, indices2, N2, "I2");
    gx_csv_file_add_column(file, values2,  N2, "V2");

    g_free(indices1);
    g_free(values1);
    g_free(indices2);
    g_free(values2);

    GError* error = NULL;
    gx_csv_file_write_to_disk(file, "tests/test_csv.csv", "tests/test_csv.plot", &error);
    if (error) {
        g_printerr("Failed to write csv_file to disk. error is : %s\n", error->message);
        goto error;
    }

    /* Test generated data aginst reference file */

    gsize length1 = 0;
    g_file_get_contents("tests/test_csv.csv", &produced_file_content, &length1, &error);
    if (error) {
        g_printerr("Failed to get produced file content from disk. error is : %s\n", error->message);
        goto error;
    }

    gsize length2 = 0;
    g_file_get_contents("tests/test_data/test_csv.csv", &reference_file_content, &length2, &error);
    if (error) {
        g_printerr("Failed to get reference file content from disk. error is : %s\n", error->message);
        goto error;
    }

    g_assert_true(length1 == length2);
    
    gboolean are_equals = TRUE;
    int i = 0;
    do {
        if (produced_file_content[i] != reference_file_content[i])
            are_equals = FALSE;
        i++;
    } while ( i < length1);

    g_assert_true(are_equals);



error:

    gx_csv_file_unref(file);

    if (produced_file_content != NULL)
        g_free(produced_file_content);

    if (reference_file_content != NULL)
        g_free(reference_file_content);

    
    struct mallinfo memory_info_end = mallinfo();

    g_assert_true(memory_info_begin.uordblks == memory_info_end.uordblks);

}

int main(int argc, char** argv) {

    gx_printf_c(BLUE,"Test gx_test_csv_file started\n");
    
    g_test_init(&argc, &argv, NULL);

    g_test_add_func("/csv_file/correct_behaviour", test_correct_behaviour);

    return g_test_run();
}