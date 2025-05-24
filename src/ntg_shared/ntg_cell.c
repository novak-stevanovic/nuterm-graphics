#include <stdlib.h>

#include "ntg_base/ntg_cell.h"

struct ntg_cell ntg_cell_new(uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style)
{
    return (struct ntg_cell) {
        ._type = NTG_CELL_TYPE_REGULAR,
        .codepoint = codepoint,
        .gfx = { .fg = fg, .bg = bg, .style = style },
    };
}

struct ntg_cell ntg_cell_new_overlay(uint32_t codepoint,
        nt_color_t fg, nt_style_t style)
{
    return (struct ntg_cell) {
        ._type = NTG_CELL_TYPE_OVERLAY,
        .codepoint = codepoint,
        .gfx = { .fg = fg, .bg = NT_COLOR_DEFAULT, .style = style },
    };
}

struct ntg_cell ntg_cell_new_transparent()
{
    return (struct ntg_cell) {
        ._type = NTG_CELL_TYPE_OVERLAY,
        .codepoint = NTG_CELL_EMPTY,
        .gfx = { .fg = NT_COLOR_DEFAULT, .bg = NT_COLOR_DEFAULT, .style = NT_STYLE_DEFAULT },
    };
}

struct ntg_cell ntg_cell_default()
{
    return (struct ntg_cell) {
        ._type = NTG_CELL_TYPE_REGULAR,
        .codepoint = NTG_CELL_EMPTY,
        .gfx = NT_GFX_DEFAULT
    };
}

struct ntg_cell ntg_cell_overwrite(struct ntg_cell overwriting,
        struct ntg_cell overwritten)
{
    if(overwritten._type != NTG_CELL_TYPE_REGULAR)
        return ntg_cell_default();

    struct ntg_cell ret;
    switch(overwriting._type)
    {
        case NTG_CELL_TYPE_REGULAR:
            ret = overwriting;
        case NTG_CELL_TYPE_OVERLAY:
            ret = (struct ntg_cell) {
                ._type = NTG_CELL_TYPE_REGULAR,
                .codepoint = overwriting.codepoint,
                .gfx = {
                    .fg = overwriting.gfx.fg,
                    .bg = overwritten.gfx.bg,
                    .style = overwriting.gfx.style,
                }
            };
        case NTG_CELL_TYPE_TRANSPARENT:
            ret = overwritten;
    }

    return ret;
}

struct ntg_cell_grid
{
    struct ntg_cell* data;
    struct ntg_xy size;
};

ntg_cell_grid_t* ntg_cell_grid_new(struct ntg_xy size)
{
    ntg_cell_grid_t* new = (ntg_cell_grid_t*)malloc(sizeof(struct ntg_cell_grid));
    if(new == NULL) return NULL;

    new->data = (struct ntg_cell*)malloc(size.x * size.y *
            sizeof(struct ntg_cell));
    if(new->data == NULL)
    {
        free(new);
        return NULL;
    }

    new->size = size;
    return new;
}

void ntg_cell_grid_destroy(ntg_cell_grid_t* grid)
{
    if(grid == NULL) return;

    if(grid->data != NULL)
        free(grid->data);

    free(grid);
}

struct ntg_cell* ntg_cell_grid_at(ntg_cell_grid_t* grid, struct ntg_xy pos)
{
    if(grid == NULL) return NULL;

    if((pos.x >= grid->size.x) || (pos.y >= grid->size.y))
        return NULL;
    else
        return &(grid->data[pos.y * grid->size.x + pos.x]);
}

struct ntg_xy ntg_cell_grid_get_size(ntg_cell_grid_t* grid)
{
    if(grid == NULL)
        return (struct ntg_xy) {0};
    else
        return grid->size;
}
