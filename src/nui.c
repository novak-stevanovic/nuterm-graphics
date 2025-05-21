#include "nui.h"
#include "_nui_shared.h"
#include "nui_shared.h"
#include "pthread.h"

static pthread_t _nui_thread;
static void* (*_init_gui_func)(void* data) = NULL; 
static void* _init_gui_func_data = NULL;

static void* _nui_thread_func(void* data)
{
    return _init_gui_func(_init_gui_func_data);
}

void nui_launch(void* (*init_gui_func)(void* data), void* data,
        nui_status_t* out_status)
{
    if(init_gui_func == NULL)
        _vreturn(out_status, NUI_ERR_INVALID_ARG);

    _init_gui_func = init_gui_func;
    _init_gui_func_data = data;

    int status = pthread_create(&_nui_thread, NULL, _nui_thread_func, data);
    if(status != 0)
        _vreturn(out_status, NUI_ERR_UNEXPECTED);

    _vreturn(out_status, NUI_SUCCESS);
}

void* nui_destroy()
{
    void* _data;
    pthread_join(_nui_thread, &_data);

    return _data;
}
