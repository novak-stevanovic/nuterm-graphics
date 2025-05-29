#include <assert.h>
#include <stdlib.h>

#include "ntg_base/ntg_cell.h"

typedef enum ntg_cell_type 
{ 
    NTG_CELL_TYPE_REGULAR,
    NTG_CELL_TYPE_TRANSPARENT,
    NTG_CELL_TYPE_OVERLAY 
} ntg_cell_type_t;

typedef struct ntg_cell
{
    struct ntg_cell_base _base;
    ntg_cell_type_t _type;
} ntg_cell_t;


struct ntg_cell_grid
{
    struct ntg_cell* data;
    struct ntg_xy size;
};

void ntg_cell_init(ntg_cell_t* cell, uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style)
{
    assert(0);
}

void ntg_cell_init_overlay(ntg_cell_t* cell, uint32_t codepoint,
        nt_color_t fg, nt_style_t style)
{
    assert(0);
}

void ntg_cell_init_transparent(ntg_cell_t* cell)
{
    assert(0);
}

void ntg_cell_init_default(ntg_cell_t* cell)
{
    assert(0);
}

struct ntg_cell_base ntg_cell_overwrite(struct ntg_cell overwriting,
        struct ntg_cell_base overwritten)
{
    assert(0);
}

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

struct ntg_cell* ntg_cell_grid_at(const ntg_cell_grid_t* grid, struct ntg_xy pos)
{
    if(grid == NULL) return NULL;

    if((pos.x >= grid->size.x) || (pos.y >= grid->size.y))
        return NULL;
    else
        return &(grid->data[pos.y * grid->size.x + pos.x]);
}

void ntg_cell_grid_realloc(ntg_cell_grid_t* grid, struct ntg_xy size)
{
    assert(0);
}

struct ntg_xy ntg_cell_grid_get_size(const ntg_cell_grid_t* grid)
{
    if(grid == NULL)
        return (struct ntg_xy) {0};
    else
        return grid->size;
}
