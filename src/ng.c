#include "ng.h"
#include "_ng_shared.h"
#include "ng_shared.h"
#include "pthread.h"
#include "nuterm.h"
#include "ng_display.h"
#include "ng_draw_engine.h"

static pthread_t _ng_thread;
static void* (*_init_gui_func)(void* data) = NULL; 
static void* _init_gui_func_data = NULL;

static void* _ng_thread_func(void* data)
{
    return _init_gui_func(_init_gui_func_data);
}

void ng_launch(void* (*init_gui_func)(void* data), void* data,
        ng_status_t* out_status)
{
    if(init_gui_func == NULL)
        _vreturn(out_status, NG_ERR_INVALID_ARG);

    nt_status_t _status;
    nt_init(&_status);
    switch(_status)
    {
        // TODO handle other cases
        case NT_SUCCESS:
            break;
        case NT_ERR_ALLOC_FAIL:
            _vreturn(out_status, NG_ERR_UNEXPECTED);
        default:
            _vreturn(out_status, NG_ERR_UNEXPECTED);
    }
    __ng_display_init__();
    __ng_draw_engine_init__();

    _init_gui_func = init_gui_func;
    _init_gui_func_data = data;

    int status = pthread_create(&_ng_thread, NULL, _ng_thread_func, data);
    if(status != 0)
        _vreturn(out_status, NG_ERR_UNEXPECTED);

    _vreturn(out_status, NG_SUCCESS);
}

void* ng_destroy()
{
    void* _data;
    pthread_join(_ng_thread, &_data);

    __ng_display_deinit__();
    __ng_draw_engine_deinit__();
    nt_destroy();

    return _data;
}
