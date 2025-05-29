#ifndef _NTG_CELL_H_
#define _NTG_CELL_H_

#include <stdint.h>
#include "nuterm.h"
#include "ntg_shared/ntg_xy.h"

#define NTG_CELL_EMPTY ' '

struct ntg_cell_base
{
    uint32_t codepoint;
    struct nt_gfx gfx;
};

typedef struct ntg_cell ntg_cell_t;

void ntg_cell_init(ntg_cell_t* cell, uint32_t codepoint,
        nt_color_t fg, nt_color_t bg, nt_style_t style);

void ntg_cell_init_overlay(ntg_cell_t* cell, uint32_t codepoint,
        nt_color_t fg, nt_style_t style);

void ntg_cell_init_transparent(ntg_cell_t* cell);
/* Regular cell with no content, default fg, bg and style. */
void ntg_cell_init_default(ntg_cell_t* cell);

struct ntg_cell_base ntg_cell_overwrite(struct ntg_cell overwriting,
        struct ntg_cell_base overwritten);

/* -------------------------------------------------------------------------- */

typedef struct ntg_cell_grid ntg_cell_grid_t;

ntg_cell_grid_t* ntg_cell_grid_new(struct ntg_xy size);
void ntg_cell_grid_destroy(ntg_cell_grid_t* grid);

/* Returns NULL if `buff` is NULL or given coordinates are out of bounds. */
struct ntg_cell* ntg_cell_grid_at(const ntg_cell_grid_t* grid,
        struct ntg_xy pos);

void ntg_cell_grid_realloc(ntg_cell_grid_t* grid, struct ntg_xy size);

struct ntg_xy ntg_cell_grid_get_size(const ntg_cell_grid_t* grid);

#endif // _NTG_CELL_H_
