#ifndef _NUI_H_
#define _NUI_H_

#include "nui_shared.h"

void nui_launch(void* (*init_gui_func)(void* data), void* data,
        nui_status_t* out_status);

/* This function returns the return value of `init_gui_func` passed in
 * nui_launch() func. */
void* nui_destroy();

#endif // _NUI_H_
