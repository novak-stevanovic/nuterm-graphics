/* TODO:
 * 1. ntg_scene.h (ntg_scene_manager(?) & ntg_scene_renderer)
 * 2. avoid malloc() in ntg_drawable.c (arena allocator)
 * 3. ntg_cell.c
 * 4. ntg_scene.c (map<ntg_object_t*, struct scene_node(?)>)
 */
#ifndef _NTG_H_
#define _NTG_H_

#include "ntg_shared/ntg_status.h"

typedef void (*ntg_init_gui_func_t)(void*);

void ntg_launch(ntg_init_gui_func_t init_gui_func, void* data,
        ntg_status_t* out_status);

/* This function returns the return value of `init_gui_func` passed in
 * nui_launch() func. */
void* ntg_destroy();

#endif // _NTG_H_
