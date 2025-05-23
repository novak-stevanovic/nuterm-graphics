#ifndef __NUI_DEFS_H__
#define __NUI_DEFS_H__

#include "nui_shared.h"

/* This file contains NUI Object definitions. Include only when necessary
 * (using struct composition). */

#ifndef __NUI_ALLOW_OBJECT_DEFS__
// #error "You should only include this file under very specific circumstances."
#endif // __NUI_ALLOW_OBJECT_DEFS__

struct _nui_object
{
    struct _nui_container* parent;

    /* Calculate size based on internal state and given constraints `constr` */
    struct nt_size (*measure_func)(struct _nui_object* self,
            struct nui_constraints constr);

    void (*arrange_func)(struct _nui_object* self);

    void (*draw_func)(struct _nui_object* self);
};

struct _nui_container
{
    struct _nui_object _base;
};

#endif // __NUI_DEFS_H__
