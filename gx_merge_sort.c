
#include <malloc.h>
#include <string.h>

#include "gx_merge_sort.h"


void gx_merge_sort_r(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp, void* temp);

void gx_merge_sort(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp) {

    void* temp = g_malloc(elem_size * nb_elements);

    gx_merge_sort_r(t, elem_size, nb_elements, cmp, temp);

    g_free(temp);

}

#define elem_index(a,e_size,i) (gchar*)(((gchar*)a) + i * e_size)
#define elem_swap(a,e_size,x,y) do {                                            \
            memcpy(_temp_swap,elem_index(t,e_size,y),e_size);                   \
            memcpy(elem_index(t,e_size,y),elem_index(t,e_size,x),e_size);       \
            memcpy(elem_index(t,e_size,x),_temp_swap,e_size);                   \
            } while(0)                                                          \


void gx_merge_sort_r(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp, void* temp) {

    if (nb_elements <= 2) {
        if (nb_elements == 2)
            if (cmp(t, t + elem_size) > 0) {
                void* _temp_swap = g_alloca(elem_size);
                elem_swap(t, elem_size, 0, 1);
            }
        return;
    }

    gint n_a = nb_elements / 2;
    gint n_b = nb_elements - n_a;

    gchar* ta = t;
    gchar* tb = t + elem_size * n_a;

    gx_merge_sort_r(ta, elem_size, n_a, cmp, temp);
    gx_merge_sort_r(tb, elem_size, n_b, cmp, temp);

    gchar* a = ta;
    gchar* b = tb;
    gchar* a_end = ta + elem_size * n_a;
    gchar* b_end = tb + elem_size * n_b;
    gchar* tempi = temp;

    while (a != a_end && b != b_end) {
        if (cmp(a, b) <= 0) {
            *(gint*) temp = *(gint*) a;
            a += elem_size;
        } else {
            *(gint*) temp = *(gint*) b;
            b += elem_size;
        }
        temp += elem_size;
    }

    gsize sorted_size = (a - ta) + (b - tb);

    if (a != a_end) {
        memcpy(ta + sorted_size, a, (a_end - a));
    }

    memcpy(t, tempi, sorted_size);

}

