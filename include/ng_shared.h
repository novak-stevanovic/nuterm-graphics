#ifndef _NG_SHARED_H_
#define _NG_SHARED_H_

#include <stdint.h>
#include <nuterm.h>

typedef int ng_status_t;

#define NG_SUCCESS 0
#define NG_ERR_UNEXPECTED 1
#define NG_ERR_INVALID_ARG 2
#define NG_ERR_MAX_THREAD 3
#define NG_ERR_ALLOC_FAIL 4

#define NG_CELL_EMPTY ' '

struct ng_xy
{
    size_t x, y;
};

#define NG_XY(xv, yv) ((struct ng_xy) { .x = (xv), .y = (yv) })

struct ng_bounds
{
    struct ng_xy min_size, max_size;
};

struct ng_cell
{
    uint32_t codepoint;
    struct nt_gfx gfx;
};

typedef struct ng_canvas* ng_canvas_t;

ng_canvas_t ng_canvas_new(struct ng_xy size);
void ng_canvas_destroy(ng_canvas_t canvas);

/* Returns NULL if `buff` is NULL or given coordinates are out of bounds. */
struct ng_cell* ng_canvas_at(ng_canvas_t canvas, struct ng_xy pos);

struct ng_xy ng_canvas_size(ng_canvas_t canvas);

#endif // _NG_SHARED_H_
