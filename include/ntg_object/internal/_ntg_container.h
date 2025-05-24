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
};

void __ntg_container_init__(struct ntg_container* container);
void __ntg_container_destroy__(struct ntg_container* container);

#endif // __NTG_CONTAINER_H__
