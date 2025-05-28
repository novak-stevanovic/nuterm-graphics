#include "ntg_object/ntg_object_shared.h"

#define _MAX_CHILDREN 15

typedef struct ntg_cconstraints
{
    struct
    {
        ntg_object_t* _child;
        struct ntg_constraints _constr;
    } _constraints[_MAX_CHILDREN];

    size_t _count;

} ntg_cconstraints_t;

typedef struct ntg_csizes
{
    struct
    {
        ntg_object_t* _child;
        struct ntg_xy size;
    } _sizes[_MAX_CHILDREN];

    size_t _count;

} ntg_csizes_t;

typedef struct ntg_cpositions
{
    struct
    {
        ntg_object_t* _child;
        struct ntg_xy position;
    } _positions[_MAX_CHILDREN];

    size_t _count;

} ntg_cpositions_t;

/* -------------------------------------------------------------------------- */

struct ntg_constraints ntg_cconstraints_get(const ntg_cconstraints_t* constrs,
        const ntg_object_t* child);

struct ntg_constraints ntg_cconstraints_at(const ntg_cconstraints_t* constrs,
        size_t idx);

void ntg_cconstraints_set(ntg_cconstraints_t* constrs,
        struct ntg_constraints constr,
        const ntg_object_t* child);

/* -------------------------------------------------------------------------- */

typedef struct ntg_csizes ntg_csizes_t;

struct ntg_xy ntg_csizes_get(const ntg_csizes_t* sizes,
        const ntg_object_t* child);

struct ntg_xy ntg_csizes_at(const ntg_cconstraints_t* constrs, size_t idx);

void ntg_csizes_set(ntg_csizes_t* sizes, struct ntg_xy size,
        const ntg_object_t* child);

/* -------------------------------------------------------------------------- */

typedef struct ntg_cpositions ntg_cpositions_t;

struct ntg_xy ntg_cpositions_get(const ntg_cpositions_t* positions,
        const ntg_object_t* child);

struct ntg_xy ntg_cpositions_at(const ntg_cpositions_t* positions, size_t idx);

void ntg_cpositions_set(ntg_cpositions_t* positions, struct ntg_xy position,
        const ntg_object_t* child);
