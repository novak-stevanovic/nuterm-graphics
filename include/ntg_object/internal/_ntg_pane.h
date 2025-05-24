#ifndef __NTG_PANE_H__
#define __NTG_PANE_H__

#define __NTG_ALLOW_NTG_OBJECT_DEF__
#include "ntg_object/internal/_ntg_object.h"
#undef __NTG_ALLOW_NTG_OBJECT_DEF__

typedef struct ntg_cell_grid ntg_cell_grid_t;

#ifndef __NTG_ALLOW_NTG_PANE_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NTG_ALLOW_NTG_PANE_DEF__

struct ntg_pane
{
    struct ntg_object _base;
    ntg_cell_grid_t* canvas;
};

void __ntg_pane_init__(struct ntg_pane* pane);
void __ntg_pane_destroy__(struct ntg_pane* pane);

#endif // __NTG_PANE_H__
