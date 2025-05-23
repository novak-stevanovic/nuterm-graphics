#ifndef _NG_DISPLAY_H_
#define _NG_DISPLAY_H_

#include "ng_shared.h"

void __ng_display_init__();
void __ng_display_deinit__();

void ng_display_draw(ng_canvas_t canvas, struct ng_xy pos);
const ng_canvas_t ng_display_buffer();

#endif // _NG_DISPLAY_H_
