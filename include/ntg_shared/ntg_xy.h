#ifndef _NTG_XY_H_
#define _NTG_XY_H_

#include <stddef.h>

struct ntg_xy
{
    size_t x, y;
};

#define NTG_XY(xv, yv) ((struct ntg_xy) { .x = (xv), .y = (yv) })

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

#endif // _NTG_XY_H_
