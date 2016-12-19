
#ifndef GX_PRINTF_H
#define GX_PRINTF_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS

enum {
    BLUE
};
        
gint gx_printf_c(gint color,const gchar * str,...);
        
        
        
        
G_END_DECLS

#endif 

