
#include <glib-2.0/glib.h>
#include <glib-2.0/glib/gprintf.h>
#include <stdio.h>


GSList* make_list(gsize s){
    
    GRand* rand = g_rand_new();
    
    
    if ( s <= 0)
        return NULL;
    
    GSList start,*current;
    current = &start;
    
    for(gint i = 0; i < s;i++){
        GSList* e = g_slice_new(GSList);
        e->data = GINT_TO_POINTER(g_rand_int_range(rand,0,10000));
        current->next = e;
        current = current->next;        
    };
    
    return start.next;
    
}

void print_elem(gpointer e,gpointer user_data){
    glong l = GPOINTER_TO_INT(e);
    g_printf("%d-",l);
}




int main(){
    
    GSList* list = make_list(10);
    g_printf("%d",g_slist_length(list));
    g_slist_foreach(list,print_elem,NULL);
    
}
