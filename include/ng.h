#ifndef _NG_H_
#define _NG_H_

#include "ng_shared.h"

void ng_launch(void* (*init_gui_func)(void* data), void* data,
        ng_status_t* out_status);

/* This function returns the return value of `init_gui_func` passed in
 * nui_launch() func. */
void* ng_destroy();

#endif // _NG_H_
