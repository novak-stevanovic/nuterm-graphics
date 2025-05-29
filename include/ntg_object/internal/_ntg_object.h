#ifndef __NTG_OBJECT_H__
#define __NTG_OBJECT_H__

#include "ntg_object/ntg_drawable.h"

#ifndef __NTG_ALLOW_NTG_OBJECT_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_OBJECT_DEF__

struct ntg_obj_constr;

struct ntg_object
{
    struct ntg_container* parent;

    ntg_ideal_size_fn ideal_size_fn;
    ntg_constrain_fn constrain_fn;
    ntg_measure_fn measure_fn;
    ntg_draw_fn draw_fn;
};

#endif // __NTG_OBJECT_H__
