#ifndef __NTG_OBJECT_H__
#define __NTG_OBJECT_H__

#include "ntg_object/ntg_object_shared.h"

#ifndef __NTG_ALLOW_NTG_OBJECT_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_OBJECT_DEF__

struct ntg_obj_constr;

struct ntg_object
{
    struct ntg_container* _parent;

};

#endif // __NTG_OBJECT_H__
