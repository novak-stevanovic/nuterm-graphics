#ifndef _NTG_DISPLAY_H_
#define _NTG_DISPLAY_H_

#include "ntg_base/ntg_cell.h"

void __ntg_display_init__();
void __ntg_display_deinit__();

void ntg_display_draw(const ntg_cell_grid_t* grid, struct ntg_xy pos);
const ntg_cell_grid_t* ntg_display_get_canvas();

#endif // _NTG_DISPLAY_H_
