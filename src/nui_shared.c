#include "nui_shared.h"
#include <stdlib.h>

struct nui_grid
{
    struct nui_cell* data;
    struct nui_size size;
};

nui_grid_t nui_grid_new(struct nui_size size)
{
    nui_grid_t new = (nui_grid_t)malloc(sizeof(struct nui_grid));
    if(new == NULL) return NULL;

    new->data = (struct nui_cell*)malloc(size.x * size.y *
            sizeof(struct nui_cell));
    if(new->data == NULL)
    {
        free(new);
        return NULL;
    }

    new->size = size;
    return new;
}

void nui_grid_destroy(nui_grid_t grid)
{
    if(grid == NULL) return;

    if(grid->data != NULL)
        free(grid->data);

    free(grid);
}

struct nui_cell* nui_grid_at(nui_grid_t grid, size_t x, size_t y)
{
    if(grid == NULL) return NULL;

    if((x >= grid->size.x) || (y >= grid->size.y))
        return NULL;
    else
        return &(grid->data[y * grid->size.y + x]);
}
