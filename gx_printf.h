
#ifndef GX_PRINTF_H
#define GX_PRINTF_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS

enum {
    BLUE
};
      

/**
 * gx_printf_c:
 * @color:  Color to print the text
 * @str:  String to print
 * @...: String parameters
 *
 *  print_f like fuction with colored output
 *
 * Returns: Number of character printed
 *
 */
gint gx_printf_c(gint color,const gchar * str,...);
        
        
        
        
G_END_DECLS

#endif 

