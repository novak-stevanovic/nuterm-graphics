#ifndef _NTG_CELL_H_
#define _NTG_CELL_H_

#include <stdint.h>
#include "nuterm.h"
#include "ntg_shared/ntg_xy.h"

#define NTG_CELL_EMPTY ' '

typedef enum ntg_cell_type 
{ 
    NTG_CELL_TYPE_REGULAR,
    NTG_CELL_TYPE_TRANSPARENT,
    NTG_CELL_TYPE_OVERLAY 
} ntg_cell_type_t;

/* Modifying `gfx.bg` has no effect on behavior of overlay cells in
 * ntg_cell_overwrite().
 * Modifying `codepoint` or `gfx` has no effect on behavior of transparent
 * cells in ntg_cell_overwrite(). */
struct ntg_cell
{
    ntg_cell_type_t _type;
    uint32_t codepoint;
    struct nt_gfx gfx;
};

struct ntg_cell ntg_cell_new(uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style);
struct ntg_cell ntg_cell_new_overlay(uint32_t codepoint,
        nt_color_t fg, nt_style_t style);
struct ntg_cell ntg_cell_new_transparent();
/* Regular cell with no content, default fg, bg and style. */
struct ntg_cell ntg_cell_default();

/* Assumes `overwritten` is of type NTG_CELL_TYPE_REGULAR. If not, a default
 * ntg_cell is returned. */
struct ntg_cell ntg_cell_overwrite(struct ntg_cell overwriting,
        struct ntg_cell overwritten);

/* -------------------------------------------------------------------------- */

typedef struct ntg_cell_grid ntg_cell_grid_t;

ntg_cell_grid_t* ntg_cell_grid_new(struct ntg_xy size);
void ntg_cell_grid_destroy(ntg_cell_grid_t* grid);

/* Returns NULL if `buff` is NULL or given coordinates are out of bounds. */
struct ntg_cell* ntg_cell_grid_at(ntg_cell_grid_t* grid, struct ntg_xy pos);

struct ntg_xy ntg_cell_grid_get_size(ntg_cell_grid_t* grid);

#endif // _NTG_CELL_H_
