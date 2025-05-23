#ifndef _NUI_DISPLAY_H_
#define _NUI_DISPLAY_H_

#include "nui_shared.h"

void __nui_display_init__();
void __nui_display_deinit__();

void nui_display_draw(nui_grid_t grid, size_t x, size_t y);
const nui_grid_t nui_display_buffer();

#endif // _NUI_DISPLAY_H_
