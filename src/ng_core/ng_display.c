#include "ng_core/ng_display.h"
#include <assert.h>

#define DISPLAY_MAX_WIDTH 300
#define DISPLAY_MAX_HEIGHT 100

static ng_cell_grid_t* _display;

void __ng_display_init__()
{
    _display = ng_cell_grid_new(NG_XY(DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT));
    assert(_display != NULL);

    struct ng_xy size = ng_cell_grid_get_size(_display);
    struct ng_cell* it_cell;
    size_t i, j;
    struct ng_cell default_cell = ng_cell_default();
    for(i = 0; i < size.y; i++)
    {
        for(j = 0; j < size.x; j++)
        {
            it_cell = ng_cell_grid_at(_display, NG_XY(j, i));
            (*it_cell) = default_cell;
        }
    }
}

void __ng_display_deinit__()
{
    ng_cell_grid_destroy(_display);
}

void ng_display_copy(ng_cell_grid_t* canvas, struct ng_xy pos)
{
    size_t i, j;
    struct ng_xy size = ng_cell_grid_get_size(canvas);
    struct ng_cell* it_cell_display;
    struct ng_cell* it_cell_canvas;
    for(i = 0; i < size.y; i++)
    {
        for(j = 0; j < size.x; j++)
        {
            // TODO handle edges
            it_cell_display = ng_cell_grid_at(_display, NG_XY(j+pos.x, i+pos.y));
            if(it_cell_display != NULL)
            {
                it_cell_canvas = ng_cell_grid_at(canvas, NG_XY(j, i));
                *it_cell_display = ng_cell_overwrite(*it_cell_canvas,
                        *it_cell_display);
            }
        }
    }
}

const ng_cell_grid_t* ng_display_get_canvas()
{
    return _display;
}
