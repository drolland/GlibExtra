#include "gx_tim_sort.h"
#include <string.h>

void gx_tim_sort_merge(gchar* ta, gchar *tb, gchar* tc, size_t elem_size, GCompareFunc cmp, void* temp) {

    gchar* a = ta;
    gchar* b = tb;
    gchar* a_end = tb;
    gchar* b_end = tc;
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

    memcpy(ta, tempi, sorted_size);

}

typedef struct _merge_jobs {
    gsize allocated_size;
    gsize real_size;
    gchar** t;
} MergeJobs;

MergeJobs* merge_jobs_new(gsize size){
    
    gsize pow_size = 1;
    while ( pow_size < size ){
        pow_size = pow_size << 1;
    }
    MergeJobs* jobs = g_malloc( sizeof(MergeJobs) + pow_size * sizeof(gchar*) );
    jobs->t = (gchar**)( (gchar*)jobs + sizeof(MergeJobs) ); 
    jobs->allocated_size = pow_size;
    jobs->real_size = 0;
    return jobs;
}

MergeJobs* merge_jobs_append(MergeJobs* jobs,gchar* t){
  
    if ( jobs->real_size >= jobs->allocated_size ){
        jobs->allocated_size = jobs->allocated_size << 1;
        jobs = g_realloc(jobs,sizeof(MergeJobs) + jobs->allocated_size * sizeof(gchar*));
        jobs->t = (gchar**)( (gchar*)jobs + sizeof(MergeJobs) ); 
    }

    jobs->t[jobs->real_size] = t;
    jobs->real_size++;
    return jobs;
}


enum {
    ASCENDING,
    DESCENDING
};

void gx_tim_sort(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp) {

    void* temp = g_malloc(elem_size * nb_elements);
    
    MergeJobs* jobs = merge_jobs_new(nb_elements/2);
        
    gint direction = 0;
    
    for (int i = 0; i < nb_elements - 1;) {

                
        if (cmp(t + i * elem_size, t + ( i + 1 ) * elem_size) <= 0)
            direction = ASCENDING;
        else
            direction = DESCENDING;
        i++;

        if (direction == ASCENDING)
            while (i < nb_elements - 1 && cmp(t + i * elem_size, t + ( i + 1 ) * elem_size) <= 0)
                i++;
        else if (direction == DESCENDING)
            while (i < nb_elements - 1 && cmp(t + i * elem_size, t + ( i + 1 ) * elem_size) > 0)
                i++;
 
        i++;
        jobs = merge_jobs_append(jobs,(gchar*)t + i * elem_size);

    }
    
    jobs = merge_jobs_append(jobs,(gchar*)t + nb_elements * elem_size);
    
    gchar* first = jobs->t[0];
    gchar* next = jobs->t[1];
    gchar* end = (gchar*)t + nb_elements * elem_size;
    gint i = 1;
    
    while( next != end) { 
        gx_tim_sort_merge(first,next,end,elem_size,cmp,temp); 
        i++;
        next = jobs->t[i];
    }
    
    g_free(jobs);

    g_free(temp);

}
