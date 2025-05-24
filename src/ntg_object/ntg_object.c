#include "ntg_object/ntg_object.h"
#include "ntg_shared/_ntg_shared.h"
#include <assert.h>

#define __NTG_ALLOW_NTG_OBJECT_DEF__
#include "ntg_object/internal/_ntg_object.h"
#undef __NTG_ALLOW_NTG_OBJECT_DEF__

void __ntg_object_init__(struct ntg_object* object,

    struct ntg_xy (*arrange_func)(struct ntg_object* self,
            struct ntg_constr constr),

    void (*draw_func)(struct ntg_object* self),

    ntg_status_t* out_status)
{
    if((object == NULL) || (arrange_func == NULL) || (draw_func == NULL))
    {
        _vreturn(out_status, NTG_ERR_INVALID_ARG);
    }

    object->arrange_func = arrange_func;
    object->draw_func = draw_func;
    object->parent = NULL;
    object->bounds = NTG_BOUNDS_NODRAW;

    _vreturn(out_status, NTG_SUCCESS);
}

void __ntg_object_destroy__(struct ntg_object* object, ntg_status_t* out_status)
{
    if(object == NULL) return;

    object->draw_func = NULL;
    object->arrange_func = NULL;
    object->parent = NULL;
    object->bounds = NTG_BOUNDS_NODRAW;
}

struct ntg_xy ntg_object_arrange(ntg_object_t* object, struct ntg_constr constr)
{
    if(object == NULL) return NTG_XY_NOSIZE;
    if(object->arrange_func == NULL) return NTG_XY_NOSIZE;

    return (object->arrange_func(object, constr));
}

void ntg_object_draw(ntg_object_t* object)
{
    if(object == NULL) return;
    if(object->draw_func == NULL) return;

    object->draw_func(object);
}

struct ntg_bounds ntg_object_get_bounds(ntg_object_t* object)
{
    return ((object != NULL) ? object->bounds : NTG_BOUNDS_NODRAW);
}

struct ntg_bounds ntg_object_get_bounds_rel(ntg_object_t* object)
{
    // TODO
    assert(0);
}

void ntg_object_set_bounds(ntg_object_t* object)
{
    // TODO
    assert(0);
}

ntg_container_t* ntg_object_get_parent(ntg_object_t* object)
{
    return ((object != NULL) ? object->parent : NULL);
}
