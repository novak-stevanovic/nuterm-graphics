#ifndef __NG_OBJECT_H__
#define __NG_OBJECT_H__

#include "ng_shared/ng_xy.h"
#include "ng_shared/ng_status.h"

#ifndef __NG_ALLOW_NG_OBJECT_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NG_ALLOW_NG_OBJECT_DEF__

struct ng_object
{
    struct _ng_container* parent;

    struct ng_xy position; // absolute

    /* Arrange with constraints `constr`. Return used size. Up to parent to set position. */
    struct ng_xy (*arrange_func)(struct ng_object* self,
            struct ng_constr constr);

    /* Draw externally */
    void (*draw_func)(struct ng_object* self);
};

void __ng_object_init__(struct ng_object* object,

    struct ng_xy (*arrange_func)(struct ng_object* self,
            struct ng_constr bounds),

    void (*draw_func)(struct ng_object* self),

    ng_status_t* out_status);

void __ng_object_destroy__(struct ng_object* object, ng_status_t* out_status);

#endif // __NG_OBJECT_H__
