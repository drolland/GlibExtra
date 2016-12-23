

#ifndef GX_MERGE_SORT_H
#define GX_MERGE_SORT_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS
        
void gx_merge_sort(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp);
        
        
        
G_END_DECLS

#endif 

