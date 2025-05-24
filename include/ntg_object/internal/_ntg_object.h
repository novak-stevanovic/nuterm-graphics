#ifndef __NTG_OBJECT_H__
#define __NTG_OBJECT_H__

#include "ntg_shared/ntg_xy.h"
#include "ntg_shared/ntg_status.h"

#ifndef __NTG_ALLOW_NTG_OBJECT_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_OBJECT_DEF__

struct ntg_object
{
    struct _ntg_container* parent;

    struct ntg_xy position; // absolute

    /* Arrantge with constraints `constr`. Return used size. Up to parent to set position. */
    struct ntg_xy (*arrange_func)(struct ntg_object* self,
            struct ntg_constr constr);

    /* Draw externally */
    void (*draw_func)(struct ntg_object* self);
};

void __ntg_object_init__(struct ntg_object* object,

    struct ntg_xy (*arrange_func)(struct ntg_object* self,
            struct ntg_constr bounds),

    void (*draw_func)(struct ntg_object* self),

    ntg_status_t* out_status);

void __ntg_object_destroy__(struct ntg_object* object, ntg_status_t* out_status);

#endif // __NTG_OBJECT_H__
