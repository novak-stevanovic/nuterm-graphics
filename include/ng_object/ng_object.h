#ifndef _NG_OBJECT_H_
#define _NG_OBJECT_H_

#include "ng_shared/ng_xy.h"

typedef struct ng_object ng_object_t;
typedef struct ng_container ng_container_t;

struct ng_xy ng_object_arrange(ng_object_t* object,
        struct ng_constr constr);

void ng_object_draw(ng_object_t* object);

struct ng_xy ng_object_get_position_abs(ng_object_t* object);
struct ng_xy ng_object_get_position_rel(ng_object_t* object);

ng_container_t* ng_object_get_parent(ng_object_t* object);

#endif // _NG_OBJECT_H_
