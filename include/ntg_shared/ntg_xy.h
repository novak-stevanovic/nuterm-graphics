#ifndef _NTG_XY_H_
#define _NTG_XY_H_

#include <stddef.h>
#include <stdint.h>

struct ntg_xy
{
    size_t x, y;
};

#define NTG_XY(xv, yv) ((struct ntg_xy) { .x = (xv), .y = (yv) })
#define NTG_XY_NOSIZE ((struct ntg_xy) {0})

struct ntg_constr
{
    struct ntg_xy min_size, max_size;
};

#define NTG_CONSTR(minsz, maxsz) ((struct ntg_constr) {                         \
    .min_size = ((struct ntg_xy) {                                             \
        .x = (((minsz).x <= (maxsz).x) ? minsz.x : maxsz.x)                    \
        .y = (((minsz).y <= (maxsz).y) ? minsz.y : maxsz.y)                    \
    })                                                                         \
    .max_size = ((struct ntg_xy) {                                             \
        .x = maxsz.x,                                                          \
        .y = maxsz.y                                                           \
    })                                                                         \
})                                                                             \

struct ntg_bounds
{
    struct ntg_xy start, end;
};

#define NTG_BOUNDS(startv, endv) ((struct ntg_bounds) {                        \
    .start = ((struct ntg_xy) {                                                \
        .x = (((startv).x <= (endv).x) ? (startv).x : (endv).x)                \
        .y = (((startv).y <= (endv).y) ? (startv).y : (endv).y)                \
    })                                                                         \
    .end = ((struct ntg_xy) {                                                  \
        .x = (endv).x,                                                         \
        .y = (endv).y,                                                         \
    })                                                                         \
})                                                                             \

#define NTG_BOUNDS_NODRAW ((struct ntg_bounds) { \
    .start = ((struct ntg_xy) {0}), \
    .end = ((struct ntg_xy) {0}) \
})

#endif // _NTG_XY_H_
