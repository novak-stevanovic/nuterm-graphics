#include "ntg_core/ntg_display.h"
#include <assert.h>

#define DISPLAY_MAX_WIDTH 300
#define DISPLAY_MAX_HEIGHT 100

static ntg_cell_grid_t* _display;

void __ntg_display_init__()
{
    _display = ntg_cell_grid_new(NTG_XY(DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT));
    assert(_display != NULL);

    struct ntg_xy size = ntg_cell_grid_get_size(_display);
    struct ntg_cell* it_cell;
    size_t i, j;
    struct ntg_cell default_cell = ntg_cell_default();
    for(i = 0; i < size.y; i++)
    {
        for(j = 0; j < size.x; j++)
        {
            it_cell = ntg_cell_grid_at(_display, NTG_XY(j, i));
            (*it_cell) = default_cell;
        }
    }
}

void __ntg_display_deinit__()
{
    ntg_cell_grid_destroy(_display);
}

void ntg_display_copy(ntg_cell_grid_t* canvas, struct ntg_xy pos)
{
    size_t i, j;
    struct ntg_xy size = ntg_cell_grid_get_size(canvas);
    struct ntg_cell* it_cell_display;
    struct ntg_cell* it_cell_canvas;
    for(i = 0; i < size.y; i++)
    {
        for(j = 0; j < size.x; j++)
        {
            // TODO handle edges
            it_cell_display = ntg_cell_grid_at(_display, NTG_XY(j+pos.x, i+pos.y));
            if(it_cell_display != NULL)
            {
                it_cell_canvas = ntg_cell_grid_at(canvas, NTG_XY(j, i));
                *it_cell_display = ntg_cell_overwrite(*it_cell_canvas,
                        *it_cell_display);
            }
        }
    }
}

const ntg_cell_grid_t* ng_display_get_canvas()
{
    return _display;
}
