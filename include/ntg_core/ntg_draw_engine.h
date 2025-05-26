#ifndef _NTG_DRAW_ENTGINE_H_
#define _NTG_DRAW_ENTGINE_H_

#include "ntg_object/ntg_object.h"

void __ntg_draw_engine_init__();
void __ntg_draw_engine_deinit__();

void ntg_draw_engine_draw_tree(ntg_object_t* object, struct ntg_constraints constr);

#endif // _NTG_DRAW_ENTGINE_H_
