

#include <glib-2.0/glib.h>
#include "../gx_qsort.h"
#include "gx_test_sort_common.h"
#include "../gx_macros.h"
#include "../gx_csv_file.h"
#include "../gx_merge_sort.h"
#include "../gx_printf.h"

#define MAX_N 10000
#define STEP_N 250
#define ITER_N 30

void plot_complexity_random() {

    gdouble* indices = g_malloc(1000 * sizeof (double));
    gdouble* values = g_malloc(1000 * sizeof (double));
    gdouble* indices2 = g_malloc(1000 * sizeof (double));
    gdouble* values2 = g_malloc(1000 * sizeof (double));
    gdouble* indices3 = g_malloc(1000 * sizeof (double));
    gdouble* values3 = g_malloc(1000 * sizeof (double));
    gdouble* indices4 = g_malloc(1000 * sizeof (double));
    gdouble* values4 = g_malloc(1000 * sizeof (double));
    gint i = 0;

    GTimer* timer = g_timer_new();
    GTimer* timer2 = g_timer_new();
    GTimer* timer3 = g_timer_new();
    GTimer* timer4 = g_timer_new();
    g_timer_start(timer);
    g_timer_stop(timer);
    g_timer_start(timer2);
    g_timer_stop(timer2);
    g_timer_start(timer3);
    g_timer_stop(timer3);
    g_timer_start(timer4);
    g_timer_stop(timer4);

    for (int n = STEP_N; n < MAX_N; n += STEP_N) {

        g_timer_reset(timer);
        g_timer_reset(timer2);
        g_timer_reset(timer3);
        g_timer_reset(timer4);

        gint* array = gx_generate_random_int_array(n);
        gint* t = g_malloc(sizeof(gint)*n);
        
        for (int k = 0; k < ITER_N; k++) {

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer2);

            g_qsort_with_data(t, n, sizeof (gint), cmp_func_int_data, NULL);

            g_timer_stop(timer2);

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer3);

            gx_merge_sort(t, sizeof (gint), n, cmp_func_int);

            g_timer_stop(timer3);

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer4);

            gx_qsort(t, sizeof (gint), 0, n - 1, cmp_func_int);

            g_timer_stop(timer4);

            
        }

        indices[i] = (gdouble) n;
        values[i] = g_timer_elapsed(timer, NULL);
        indices2[i] = (gdouble) n;
        values2[i] = g_timer_elapsed(timer2, NULL);
        indices3[i] = (gdouble) n;
        values3[i] = g_timer_elapsed(timer3, NULL);
        indices4[i] = (gdouble) n;
        values4[i] = g_timer_elapsed(timer4, NULL);
        i++;
        
        g_free(array);
        g_free(t);

    }

    GCsvFile* file = gx_csv_file_new();


    gx_csv_file_add_column(file, indices2, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values2, MAX_N / STEP_N - 1, "g_qsort_with_data");
    gx_csv_file_add_column(file, indices3, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values3, MAX_N / STEP_N - 1, "gx_merge_sort");
    gx_csv_file_add_column(file, indices4, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values4, MAX_N / STEP_N - 1, "gx_qsort");

    GError* error = NULL;

    gx_csv_file_write_to_disk(file, "tests/bench_sort.csv", "tests/bench_sort.plot", &error);

    g_assert_no_error(error);

    g_timer_destroy(timer);
    g_timer_destroy(timer2);
    g_timer_destroy(timer3);
    g_timer_destroy(timer4);

    g_free(indices);

    g_free(values);

    gx_csv_file_unref(file);

}

void plot_complexity_low_frag() {

    gdouble* indices = g_malloc(1000 * sizeof (double));
    gdouble* values = g_malloc(1000 * sizeof (double));
    gdouble* indices2 = g_malloc(1000 * sizeof (double));
    gdouble* values2 = g_malloc(1000 * sizeof (double));
    gdouble* indices3 = g_malloc(1000 * sizeof (double));
    gdouble* values3 = g_malloc(1000 * sizeof (double));
    gdouble* indices4 = g_malloc(1000 * sizeof (double));
    gdouble* values4 = g_malloc(1000 * sizeof (double));
    gint i = 0;

    GTimer* timer = g_timer_new();
    GTimer* timer2 = g_timer_new();
    GTimer* timer3 = g_timer_new();
    GTimer* timer4 = g_timer_new();
    g_timer_start(timer);
    g_timer_stop(timer);
    g_timer_start(timer2);
    g_timer_stop(timer2);
    g_timer_start(timer3);
    g_timer_stop(timer3);
    g_timer_start(timer4);
    g_timer_stop(timer4);

    for (int n = STEP_N; n < MAX_N; n += STEP_N) {

        g_timer_reset(timer);
        g_timer_reset(timer2);
        g_timer_reset(timer3);
        g_timer_reset(timer4);

        gint* array = gx_generate_nearly_sorted_array(n, n / 20, 10);
        gint* t = g_malloc(sizeof(gint)*n);
        
        for (int k = 0; k < ITER_N; k++) {

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer2);

            g_qsort_with_data(t, n, sizeof (gint), cmp_func_int_data, NULL);

            g_timer_stop(timer2);

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer3);

            gx_merge_sort(t, sizeof (gint), n, cmp_func_int);

            g_timer_stop(timer3);

            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer4);

            gx_qsort(t, sizeof (gint), 0, n - 1, cmp_func_int);

            g_timer_stop(timer4);
            
            memcpy(t,array,sizeof(gint)*n);

            g_timer_continue(timer);

            gx_tim_sort(t, sizeof (gint),n, cmp_func_int, NULL);

            g_timer_stop(timer);

            
        }
        
        g_free(array);
        g_free(t);
        
        indices[i] = (gdouble) n;
        values[i] = g_timer_elapsed(timer, NULL);
        indices2[i] = (gdouble) n;
        values2[i] = g_timer_elapsed(timer2, NULL);
        indices3[i] = (gdouble) n;
        values3[i] = g_timer_elapsed(timer3, NULL);
        indices4[i] = (gdouble) n;
        values4[i] = g_timer_elapsed(timer4, NULL);
        i++;

    }

    GCsvFile* file = gx_csv_file_new();

    gx_csv_file_add_column(file, indices2, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values2, MAX_N / STEP_N - 1, "g_qsort_with_data");
    gx_csv_file_add_column(file, indices3, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values3, MAX_N / STEP_N - 1, "gx_merge_sort");
    gx_csv_file_add_column(file, indices4, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values4, MAX_N / STEP_N - 1, "gx_qsort");
    gx_csv_file_add_column(file, indices, MAX_N / STEP_N - 1, "_");
    gx_csv_file_add_column(file, values, MAX_N / STEP_N - 1, "gx_tim_sort");

    GError* error = NULL;

    gx_csv_file_write_to_disk(file, "tests/bench_sort_low_frag.csv", "tests/bench_sort_low_frag.plot", &error);

    g_assert_no_error(error);

    g_timer_destroy(timer);
    g_timer_destroy(timer2);
    g_timer_destroy(timer3);
    g_timer_destroy(timer4);

    g_free(indices);

    g_free(values);

    gx_csv_file_unref(file);

}

#define MONOTIE_N 1000

enum {
    ASCENDING,
    DESCENDING
};

void plot_monotonie_random() {

    gint* t = gx_generate_nearly_sorted_array(MONOTIE_N,MONOTIE_N/20,10);

    
    gdouble* indices = g_malloc(sizeof (gdouble) * MONOTIE_N);
    for (int i = 0; i < MONOTIE_N; i++) {
        indices[i] = i;
    }
    gdouble* values = g_malloc0(sizeof (gdouble) * MONOTIE_N);

    for (int i = 0; i < MONOTIE_N - 1; i++) {

        gint direction = 0;

        if (t[i] < t[i + 1])
            direction = ASCENDING;
        else
            direction = DESCENDING;
        i++;

        gint n = 1;

        if (direction == ASCENDING) {
            while (i < MONOTIE_N - 1 && t[i + 1] >= t[i]) {
                n++;
                i++;
            }
            values[n] += 1;
        } else if (direction == DESCENDING) {
            while (i < MONOTIE_N - 1 && t[i + 1] <= t[i]) {
                n++;
                i++;
            }
            values[n] += 1;
        }

    }


    GCsvFile* file = gx_csv_file_new();

    gx_csv_file_add_column(file, indices, MONOTIE_N - 1, "_");
    gx_csv_file_add_column(file, values, MONOTIE_N - 1, "monotonie distrib");

    GError* error = NULL;

    gx_csv_file_write_to_disk(file, "tests/bench_sort_monotonie_random.csv", "tests/bench_sort_monotonie_random.plot", &error);

    if (error) {
        g_printerr("Failed to write csv_file to disk. error is : %s\n", error->message);
    }

    gx_csv_file_unref(file);

    g_free(t);
    g_free(indices);
    g_free(values);
}

int main(int argc, char** argv) {

    g_test_init(&argc, &argv, NULL);

    gx_printf_c(BLUE, "Perf Bench for sort algorithms started\n");

    g_test_add_func("/bench_sort/plot_complexity_random", plot_complexity_random);
    g_test_add_func("/bench_sort/plot_complexity_low_frag", plot_complexity_low_frag);
    g_test_add_func("/bench_sort/plot_monotonie_random", plot_monotonie_random);


    return g_test_run();
}
