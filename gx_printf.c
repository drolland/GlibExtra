#include "gx_printf.h"

#include <glib-2.0/glib/gprintf.h>

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
gint gx_printf_c(gint color, gchar const *format, ...) {
    va_list args;
    gint retval;

    switch (color) {
        case BLUE:
            g_printf("\e[34m");
            break;
        default:
            break;

    };

    va_start(args, format);
    retval = g_vprintf(format, args);
    va_end(args);

    g_printf("\e[0m");

    return retval;
}