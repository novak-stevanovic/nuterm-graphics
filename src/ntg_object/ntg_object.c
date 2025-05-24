#include "ntg_object/ntg_object.h"
#include "ntg_shared/_ntg_shared.h"

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


}

void __ntg_object_destroy__(struct ntg_object* object, ntg_status_t* out_status)
{
}

struct ntg_xy ntg_object_arrange(ntg_object_t* object, struct ntg_constr constr)
{
    if(object == NULL) return NTG_XY(0, 0);
    if(object->arrange_func == NULL) return NTG_XY(0, 0);

    return (object->arrange_func(object, constr));
}

void ntg_object_draw(ntg_object_t* object)
{
    if(object == NULL) return;
    if(object->draw_func == NULL) return;

    object->draw_func(object);
}
