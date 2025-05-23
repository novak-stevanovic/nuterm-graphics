#ifndef _NUI_SHARED_H_
#define _NUI_SHARED_H_

#include <stdint.h>
#include <nuterm.h>

typedef int nui_status_t;

#define NUI_SUCCESS 0
#define NUI_ERR_UNEXPECTED 1
#define NUI_ERR_INVALID_ARG 2
#define NUI_ERR_MAX_THREAD 3
#define NUI_ERR_ALLOC_FAIL 4

// #define nui_max2(x, y) ((x) > (y) ? (x) : (y))
// #define nui_min2(x, y) ((x) < (y) ? (x) : (y))
//
struct nui_size { size_t x, y; };
struct nui_ssize { ssize_t x, y; };

/* If x or y is 0, both will be set to 0. */
#define nui_size_new(x, y)                                                     \
    ((((x) == 0) || ((y) == 0)) ?                                              \
     (struct nui_size) { .x = 0, .y = 0 } :                                    \
     (struct nui_size) { .x = (x), .y = (y) })                                 \

#define nui_ssize_new(x, y)                                                    \
    ((((x) == 0) || ((y) == 0)) ?                                              \
     (struct nui_ssize) { .x = 0, .y = 0 } :                                   \
     (struct nui_ssize) { .x = (x), .y = (y) })                                \

struct nui_constraints
{
    struct nui_size min_size, max_size;
};

/* If min_x > max_x, min_x is set to max_x. Same applies to y. */
struct nui_constraints nui_constraints_new(struct nui_size min_size,
        struct nui_size max_size);

#define NUI_CELL_EMPTY ' '

struct nui_cell
{
    uint32_t codepoint;
    struct nt_gfx gfx;
};

typedef struct nui_grid* nui_grid_t;

nui_grid_t nui_grid_new(struct nui_size size);
void nui_grid_destroy(nui_grid_t grid);

/* Returns NULL if `buff` is NULL or given coordinates are out of bounds. */
struct nui_cell* nui_grid_at(nui_grid_t grid, size_t x, size_t y);

#endif // _NUI_SHARED_H_
