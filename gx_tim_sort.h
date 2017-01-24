/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gx_tim_sort.h
 * Author: drolland
 *
 * Created on 7 janvier 2017, 17:58
 */

#ifndef GX_TIM_SORT_H
#define GX_TIM_SORT_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS
        
void gx_tim_sort(void* t, size_t elem_size, int nb_elements, GCompareFunc cmp);
        
        
        
G_END_DECLS

#endif 

