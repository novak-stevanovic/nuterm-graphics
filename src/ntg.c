#include "ntg.h"
#include "ntg_shared/_ntg_shared.h"
#include "pthread.h"
#include "nuterm.h"
#include "ntg_core/ntg_display.h"
#include "ntg_core/ntg_draw_engine.h"

static pthread_t _ntg_thread;
static void* (*_init_gui_func)(void* data) = NULL; 
static void* _init_gui_func_data = NULL;

static void* _ntg_thread_func(void* data)
{
    return _init_gui_func(_init_gui_func_data);
}

void ntg_launch(void* (*init_gui_func)(void* data), void* data,
        ntg_status_t* out_status)
{
    if(init_gui_func == NULL)
        _vreturn(out_status, NTG_ERR_INVALID_ARG);

    nt_status_t _status;
    nt_init(&_status);
    switch(_status)
    {
        // TODO handle other cases
        case NT_SUCCESS:
            break;
        case NT_ERR_ALLOC_FAIL:
            _vreturn(out_status, NTG_ERR_UNEXPECTED);
        default:
            _vreturn(out_status, NTG_ERR_UNEXPECTED);
    }
    __ntg_display_init__();
    __ntg_draw_engine_init__();

    _init_gui_func = init_gui_func;
    _init_gui_func_data = data;

    int status = pthread_create(&_ntg_thread, NULL, _ntg_thread_func, data);
    if(status != 0)
        _vreturn(out_status, NTG_ERR_UNEXPECTED);

    _vreturn(out_status, NTG_SUCCESS);
}

void* ntg_destroy()
{
    void* _data;
    pthread_join(_ntg_thread, &_data);

    __ntg_display_deinit__();
    __ntg_draw_engine_deinit__();
    nt_destroy();

    return _data;
}
