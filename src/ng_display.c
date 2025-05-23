#include "ng_display.h"
#include <assert.h>

#define DISPLAY_MAX_WIDTH 300
#define DISPLAY_MAX_HEIGHT 100

static ng_canvas_t _display;

void __ng_display_init__()
{
    _display = ng_canvas_new(NG_XY(DISPLAY_MAX_WIDTH, DISPLAY_MAX_HEIGHT));

    assert(_display != NULL);
}

void __ng_display_deinit__()
{
    ng_canvas_destroy(_display);
}

void ng_display_draw(ng_canvas_t canvas, struct ng_xy pos)
{
    size_t i, j;
    struct ng_xy size = ng_canvas_size(canvas);
    struct ng_cell* it_cell;
    for(i = 0; i < size.y; i++)
    {
        for(j = 0; i < size.x; j++)
        {
            // TODO handle edges
            it_cell = ng_canvas_at(_display, NG_XY(i + pos.y, j + pos.x));
            (*it_cell) = *(ng_canvas_at(canvas, NG_XY(i, j)));
        }
    }
}

const ng_canvas_t ng_display_buffer()
{
    return _display;
}
