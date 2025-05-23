#ifndef __NG_DEFS_H__
#define __NG_DEFS_H__

#include "ng_shared.h"

/* This file congains NG Object definitions. Include only when necessary
 * (using struct composition). */

#ifndef __NG_ALLOW_OBJECT_DEFS__
// #error "You should only include this file under very specific circumstances."
#endif // __NG_ALLOW_OBJECT_DEFS__

struct ng_object
{
    struct _ng_container* parent;

    /* Calculate size based on ingernal state and given constraings `constr` */
    struct ng_size (*measure_func)(struct ng_object* self,
            struct ng_bounds constraints);

    void (*arrange_func)(struct ng_object* self);

    void (*draw_func)(struct ng_object* self);
};

void __ng_object_init__(struct ng_object* obj);
void __ng_object_destroy__(struct ng_object* obj);

struct ng_container
{
    struct ng_object _base;
};

#endif // __NG_DEFS_H__
