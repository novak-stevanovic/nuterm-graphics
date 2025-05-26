#include "ntg_core/ntg_draw_engine.h"
#include "ntg_core/ntg_display.h"
#include "nuterm.h"

void __ntg_draw_engine_init__()
{
}

void __ntg_draw_engine_deinit__()
{
}

void ntg_draw_engine_draw()
{
    const ntg_cell_grid_t* canvas = ntg_display_get_canvas();

    size_t _width, _height;
    nt_get_term_size(&_width, &_height);

    size_t i, j;
    struct ntg_cell* it_cell;
    nt_status_t _style;
    for(i = 0; i < _height; i++)
    {
        for(j = 0; j < _width; j++)
        {
            it_cell = ntg_cell_grid_at(canvas, NTG_XY(j, i));
            nt_write_char(it_cell->codepoint, it_cell->gfx, j, i, NULL, &_style);
        }
    }
}
