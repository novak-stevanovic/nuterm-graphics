#ifndef __NTG_CONTAINER_H__
#define __NTG_CONTAINER_H__

#define __NTG_ALLOW_NTG_OBJECT_DEF__
#include "ntg_object/internal/_ntg_object.h"
#undef __NTG_ALLOW_NTG_OBJECT_DEF__

#ifndef __NTG_ALLOW_NTG_CONTAINER_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_CONTAINER_DEF__


struct ntg_container
{
    struct ntg_object _base;

    /* Calculate constraints of children based on container's
     * current constraints. */
    void (*cntr_constrain_children_func)(struct ntg_container* self,
            struct ntg_obj_constr* out_constrs);

    struct ntg_xy (*cntr_calculate_size_func)(struct ntg_container* self);
};

/*
#define MAX_CHILDREN 100

struct ntg_xy container_measure_func(struct ntg_object* container)
{
    struct ntg_object* children = ntg_object_get_children(container);
    size_t children_count = ntg_object_get_children_count(container);

    struct ntg_obj_constr constrs[children_count];

    struct ntg_container _container = (struct ntg_container*)container;

    _container->cnt_constrain_children_func(_container, constrs);

    size_t i;
    for(i = 0; i < children_count; i++)
    {
        ntg_object_set_constr(constrs[i].object, (constrs[i].constr));
    }

    struct nt_xy size = _container->cnt_calculate_size_func(_container);

    ntg_object_set_size(_container, size);
}
*/

void __ntg_container_init__(struct ntg_container* container);
void __ntg_container_destroy__(struct ntg_container* container);

#endif // __NTG_CONTAINER_H__
