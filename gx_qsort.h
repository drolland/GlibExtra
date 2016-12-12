/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   d_sort_divide.h
 * Author: drolland
 *
 * Created on 1 décembre 2016, 19:59
 */

#ifndef D_SORT_DIVIDE_H
#define D_SORT_DIVIDE_H

#include <glib-2.0/glib.h>

G_BEGIN_DECLS

    void gx_qsort_int(int* t, int i, int j);

    void gx_qsort(gpointer a,size_t elem_size,int i,int j,GCompareFunc cmp_func);

G_END_DECLS

#endif /* D_SORT_DIVIDE_H */

