#ifndef __NG_PANE_H__
#define __NG_PANE_H__

#define __NG_ALLOW_NG_OBJECT_DEF__
#include "ng_object/internal/_ng_object.h"
#undef __NG_ALLOW_NG_OBJECT_DEF__

typedef struct ng_cell_grid ng_cell_grid_t;

#ifndef __NG_ALLOW_NG_PANE_DEF__
// #error "Only include this file under very specific circumstances."
#endif // __NG_ALLOW_NG_PANE_DEF__

struct ng_pane
{
    struct ng_object _base;
    ng_cell_grid_t* canvas;
};

void __ng_pane_init__(struct ng_pane* pane);
void __ng_pane_destroy__(struct ng_pane* pane);

#endif // __NG_PANE_H__
