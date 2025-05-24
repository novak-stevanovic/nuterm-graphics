#ifndef _NTG_OBJECT_H_
#define _NTG_OBJECT_H_

#include "ntg_shared/ntg_xy.h"

typedef struct ntg_object ntg_object_t;
typedef struct ntg_container ntg_container_t;

struct ntg_xy ntg_object_arrange(ntg_object_t* object,
        struct ntg_constr constr);

void ntg_object_draw(ntg_object_t* object);

struct ntg_xy ntg_object_get_position_abs(ntg_object_t* object);
struct ntg_xy ntg_object_get_position_rel(ntg_object_t* object);

ntg_container_t* ntg_object_get_parent(ntg_object_t* object);

#endif // _NTG_OBJECT_H_
