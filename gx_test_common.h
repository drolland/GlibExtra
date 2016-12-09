/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test_common.h
 * Author: drolland
 *
 * Created on 1 décembre 2016, 19:30
 */

#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS
    
#include <stdlib.h>

    gint* gx_generate_random_int_array(gsize size);
    
    gboolean  gx_is_int_array_sorted(gint t[],gsize size);


G_END_DECLS

#endif 

