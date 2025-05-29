#include "ntg_object/ntg_drawable.h"

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
