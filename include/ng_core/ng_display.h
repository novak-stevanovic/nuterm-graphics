#ifndef _NG_DISPLAY_H_
#define _NG_DISPLAY_H_

#include "ng_base/ng_cell.h"

void __ng_display_init__();
void __ng_display_deinit__();

void ng_display_draw(ng_cell_grid_t* grid, struct ng_xy pos);
const ng_cell_grid_t* ng_display_get_canvas();

#endif // _NG_DISPLAY_H_
