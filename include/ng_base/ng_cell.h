#ifndef _NG_CELL_H_
#define _NG_CELL_H_

#include <stdint.h>
#include "nuterm.h"
#include "ng_shared/ng_xy.h"

#define NG_CELL_EMPTY ' '

typedef enum ng_cell_type 
{ 
    NG_CELL_TYPE_REGULAR,
    NG_CELL_TYPE_TRANSPARENT,
    NG_CELL_TYPE_OVERLAY 
} ng_cell_type_t;

/* Modifying `gfx.bg` has no effect on behavior of overlay cells in
 * ng_cell_overwrite().
 * Modifying `codepoint` or `gfx` has no effect on behavior of transparent
 * cells in ng_cell_overwrite(). */
struct ng_cell
{
    ng_cell_type_t _type;
    uint32_t codepoint;
    struct nt_gfx gfx;
};

struct ng_cell ng_cell_new(uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style);
struct ng_cell ng_cell_new_overlay(uint32_t codepoint,
        nt_color_t fg, nt_style_t style);
struct ng_cell ng_cell_new_transparent();
/* Regular cell with no content, default fg, bg and style. */
struct ng_cell ng_cell_default();

/* Assumes `overwritten` is of type NG_CELL_TYPE_REGULAR. If not, a default
 * ng_cell is returned. */
struct ng_cell ng_cell_overwrite(struct ng_cell overwriting,
        struct ng_cell overwritten);

/* -------------------------------------------------------------------------- */

typedef struct ng_cell_grid ng_cell_grid_t;

ng_cell_grid_t* ng_cell_grid_new(struct ng_xy size);
void ng_cell_grid_destroy(ng_cell_grid_t* grid);

/* Returns NULL if `buff` is NULL or given coordinates are out of bounds. */
struct ng_cell* ng_cell_grid_at(ng_cell_grid_t* grid, struct ng_xy pos);

struct ng_xy ng_cell_grid_get_size(ng_cell_grid_t* grid);

#endif // _NG_CELL_H_
