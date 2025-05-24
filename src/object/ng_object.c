#include "ng_object/ng_object.h"
#include "ng_shared/_ng_shared.h"

#define __NG_ALLOW_NG_OBJECT_DEF__
#include "ng_object/internal/_ng_object.h"
#undef __NG_ALLOW_NG_OBJECT_DEF__

void __ng_object_init__(struct ng_object* object,

    struct ng_xy (*arrange_func)(struct ng_object* self,
            struct ng_constr constr),

    void (*draw_func)(struct ng_object* self),

    ng_status_t* out_status)
{

    if((object == NULL) || (arrange_func == NULL) || (draw_func == NULL))
    {
        _vreturn(out_status, NG_ERR_INVALID_ARG);
    }


}

void __ng_object_destroy__(struct ng_object* object, ng_status_t* out_status)
{
}

struct ng_xy ng_object_arrange(ng_object_t* object, struct ng_constr constr)
{
    if(object == NULL) return NG_XY(0, 0);
    if(object->arrange_func == NULL) return NG_XY(0, 0);

    return (object->arrange_func(object, constr));
}

void ng_object_draw(ng_object_t* object)
{
    if(object == NULL) return;
    if(object->draw_func == NULL) return;

    object->draw_func(object);
}
