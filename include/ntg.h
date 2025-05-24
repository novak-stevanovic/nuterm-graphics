#ifndef _NTG_H_
#define _NTG_H_

#include "ntg_shared/ntg_status.h"

void ntg_launch(void* (*init_gui_func)(void* data), void* data,
        ntg_status_t* out_status);

/* This function returns the return value of `init_gui_func` passed in
 * nui_launch() func. */
void* ntg_destroy();

#endif // _NTG_H_
