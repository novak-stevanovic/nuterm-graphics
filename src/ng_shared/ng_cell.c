#include <stdlib.h>

#include "ng_base/ng_cell.h"

struct ng_cell ng_cell_new(uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style)
{
    return (struct ng_cell) {
        ._type = NG_CELL_TYPE_REGULAR,
        .codepoint = codepoint,
        .gfx = { .fg = fg, .bg = bg, .style = style },
    };
}

struct ng_cell ng_cell_new_overlay(uint32_t codepoint,
        nt_color_t fg, nt_style_t style)
{
    return (struct ng_cell) {
        ._type = NG_CELL_TYPE_OVERLAY,
        .codepoint = codepoint,
        .gfx = { .fg = fg, .bg = NT_COLOR_DEFAULT, .style = style },
    };
}

struct ng_cell ng_cell_new_transparent()
{
    return (struct ng_cell) {
        ._type = NG_CELL_TYPE_OVERLAY,
        .codepoint = NG_CELL_EMPTY,
        .gfx = { .fg = NT_COLOR_DEFAULT, .bg = NT_COLOR_DEFAULT, .style = NT_STYLE_DEFAULT },
    };
}

struct ng_cell ng_cell_default()
{
    return (struct ng_cell) {
        ._type = NG_CELL_TYPE_REGULAR,
        .codepoint = NG_CELL_EMPTY,
        .gfx = NT_GFX_DEFAULT
    };
}

struct ng_cell ng_cell_overwrite(struct ng_cell overwriting,
        struct ng_cell overwritten)
{
    if(overwritten._type != NG_CELL_TYPE_REGULAR)
        return ng_cell_default();

    struct ng_cell ret;
    switch(overwriting._type)
    {
        case NG_CELL_TYPE_REGULAR:
            ret = overwriting;
        case NG_CELL_TYPE_OVERLAY:
            ret = (struct ng_cell) {
                ._type = NG_CELL_TYPE_REGULAR,
                .codepoint = overwriting.codepoint,
                .gfx = {
                    .fg = overwriting.gfx.fg,
                    .bg = overwritten.gfx.bg,
                    .style = overwriting.gfx.style,
                }
            };
        case NG_CELL_TYPE_TRANSPARENT:
            ret = overwritten;
    }

    return ret;
}

struct ng_cell_grid
{
    struct ng_cell* data;
    struct ng_xy size;
};

ng_cell_grid_t* ng_cell_grid_new(struct ng_xy size)
{
    ng_cell_grid_t* new = (ng_cell_grid_t*)malloc(sizeof(struct ng_cell_grid));
    if(new == NULL) return NULL;

    new->data = (struct ng_cell*)malloc(size.x * size.y *
            sizeof(struct ng_cell));
    if(new->data == NULL)
    {
        free(new);
        return NULL;
    }

    new->size = size;
    return new;
}

void ng_cell_grid_destroy(ng_cell_grid_t* grid)
{
    if(grid == NULL) return;

    if(grid->data != NULL)
        free(grid->data);

    free(grid);
}

struct ng_cell* ng_cell_grid_at(ng_cell_grid_t* grid, struct ng_xy pos)
{
    if(grid == NULL) return NULL;

    if((pos.x >= grid->size.x) || (pos.y >= grid->size.y))
        return NULL;
    else
        return &(grid->data[pos.y * grid->size.x + pos.x]);
}

struct ng_xy ng_cell_grid_get_size(ng_cell_grid_t* grid)
{
    if(grid == NULL)
        return (struct ng_xy) {0};
    else
        return grid->size;
}
