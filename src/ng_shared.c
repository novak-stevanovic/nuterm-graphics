#include "ng_shared.h"
#include <stdlib.h>

struct ng_canvas
{
    struct ng_cell* data;
    struct ng_xy size;
};

ng_canvas_t ng_canvas_new(struct ng_xy size)
{
    ng_canvas_t new = (ng_canvas_t)malloc(sizeof(struct ng_canvas));
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

void ng_canvas_destroy(ng_canvas_t canvas)
{
    if(canvas == NULL) return;

    if(canvas->data != NULL)
        free(canvas->data);

    free(canvas);
}

struct ng_cell* ng_canvas_at(ng_canvas_t canvas, struct ng_xy pos)
{
    if(canvas == NULL) return NULL;

    if((pos.x >= canvas->size.x) || (pos.y >= canvas->size.y))
        return NULL;
    else
        return &(canvas->data[pos.y * canvas->size.y + pos.x]);
}

struct ng_xy ng_canvas_size(ng_canvas_t canvas)
{
    if(canvas == NULL)
        return (struct ng_xy) { .x = 0, .y = 0 };
    else
        return (struct ng_xy) { .x = canvas->size.x, .y = canvas->size.y };
}
