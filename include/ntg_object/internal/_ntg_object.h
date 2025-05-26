#ifndef __NTG_OBJECT_H__
#define __NTG_OBJECT_H__

#include "ntg_shared/ntg_xy.h"

#ifndef __NTG_ALLOW_NTG_OBJECT_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_OBJECT_DEF__

struct ntg_obj_constr;

struct ntg_object
{
    struct ntg_container* _parent;

    // struct ntg_bounds bounds; // ABS

    struct ntg_constraints _constraints;
    struct ntg_xy _size;
    struct ntg_xy _start_pos;
    
    /* Calculate size based on object's current constraints. */
    struct ntg_xy (*_obj_measure_func)(struct ntg_object* self);

    /* Arrange content based on object' current size. */
    struct ntg_xy (*_obj_arrange_func)(struct ntg_object* self);
};

#endif // __NTG_OBJECT_H__
