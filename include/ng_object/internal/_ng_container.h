#ifndef __NG_CONTAINER_H__
#define __NG_CONTAINER_H__

#define __NG_ALLOW_NG_OBJECT_DEF__
#include "ng_object/internal/_ng_object.h"
#undef __NG_ALLOW_NG_OBJECT_DEF__

#ifndef __NG_ALLOW_NG_CONTAINER_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NG_ALLOW_NG_CONTAINER_DEF__

struct ng_container
{
    struct ng_object _base;
};

void __ng_container_init__(struct ng_container* container);
void __ng_container_destroy__(struct ng_container* container);

#endif // __NG_CONTAINER_H__
