#ifndef _NTG_DRAWABLE_H_
#define _NTG_DRAWABLE_H_

#include "ntg_shared/ntg_xy.h"

#include <stdbool.h>

typedef struct ntg_object ntg_object_t;
typedef struct ntg_cell_grid ntg_cell_grid_t;

typedef struct ntg_cconstraints ntg_cconstraints_t;
typedef struct ntg_cxys ntg_csizes_t;
typedef struct ntg_cxys ntg_cpositions_t;

/* ------------------------------------------------------ */

typedef struct ntg_xy (*ntg_ideal_size_fn)(const ntg_object_t* self);

typedef void (*ntg_constrain_fn)(const ntg_object_t* self,
        ntg_cconstraints_t* out_cconstr);

typedef struct nt_xy (*ntg_measure_fn)(const ntg_object_t* self,
        struct ntg_constraints constr,
        const ntg_csizes_t* csizes);

typedef void (*ntg_arrange_fn)(const ntg_object_t* self, struct nt_xy size,
        const ntg_csizes_t* csizes, ntg_cpositions_t* out_cpositions);

typedef bool (*ntg_draw_fn)(const ntg_object_t* self,
        ntg_cell_grid_t* out_canvas);

/* -------------------------------------------------------------------------- */

ntg_cconstraints_t* ntg_cconstraints_create(size_t count);
void ntg_cconstraints_destroy(ntg_cconstraints_t* constrs);

struct ntg_constraints ntg_cconstraints_get(const ntg_cconstraints_t* constrs,
        const ntg_object_t* child);

struct ntg_constraints ntg_cconstraints_at(const ntg_cconstraints_t* constrs,
        size_t idx);

void ntg_cconstraints_set(ntg_cconstraints_t* constrs,
        struct ntg_constraints constr,
        const ntg_object_t* child);

/* -------------------------------------------------------------------------- */

ntg_csizes_t* ntg_csizes_create(size_t count);
void ntg_csizes_destroy(ntg_csizes_t* sizes);

struct ntg_xy ntg_csizes_get(const ntg_csizes_t* sizes,
        const ntg_object_t* child);

struct ntg_xy ntg_csizes_at(const ntg_csizes_t* sizes, size_t idx);

void ntg_csizes_set(ntg_csizes_t* sizes, struct ntg_xy size,
        const ntg_object_t* child);

/* -------------------------------------------------------------------------- */

ntg_cpositions_t* ntg_cpositions_create(size_t count);
void ntg_cpositions_destroy(ntg_cpositions_t* positions);

struct ntg_xy ntg_cpositions_get(const ntg_cpositions_t* positions,
        const ntg_object_t* child);

struct ntg_xy ntg_cpositions_at(const ntg_cpositions_t* positions, size_t idx);

void ntg_cpositions_set(ntg_cpositions_t* positions, struct ntg_xy position,
        const ntg_object_t* child);

#endif // _NTG_DRAWABLE_H_
