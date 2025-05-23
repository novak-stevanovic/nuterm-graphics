#include "nui_shared.h"
#include <assert.h>

#define DISPLAY_MAX_WIDTH 300
#define DISPLAY_MAX_HEIGHT 100

static nui_grid_t _grid;

void __nui_display_init__()
{
    struct nui_size size = { .x = DISPLAY_MAX_WIDTH, .y = DISPLAY_MAX_HEIGHT };
    _grid = nui_grid_new(size);

    assert(_grid != NULL);
}

void __nui_display_deinit__()
{
}

void nui_display_draw(nui_grid_t grid, size_t x, size_t y)
{
}

const nui_grid_t nui_display_buffer()
{
}
