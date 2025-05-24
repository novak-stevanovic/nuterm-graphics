#ifndef _NG_XY_H_
#define _NG_XY_H_

#include <stddef.h>

struct ng_xy
{
    size_t x, y;
};

#define NG_XY(xv, yv) ((struct ng_xy) { .x = (xv), .y = (yv) })

struct ng_constr
{
    struct ng_xy min_size, max_size;
};

#define NG_CONSTR(minsz, maxsz) ((struct ng_constr) {                          \
    .min_size = ((struct ng_xy) {                                              \
        .x = (((minsz).x <= (maxsz).x) ? minsz.x : maxsz.x)                    \
        .y = (((minsz).y <= (maxsz).y) ? minsz.y : maxsz.y)                    \
    })                                                                         \
    .max_size = ((struct ng_xy) {                                              \
        .x = maxsz.x,                                                          \
        .y = maxsz.y                                                           \
    })                                                                         \
})                                                                             \

#endif // _NG_XY_H_
