#ifndef _NTG_OBJECT_H_
#define _NTG_OBJECT_H_

typedef struct ntg_object ntg_object_t;
typedef struct ntg_container ntg_container_t;

void ntg_object_arrange(ntg_object_t* object);

void ntg_object_draw(ntg_object_t* object);

ntg_container_t* ntg_object_get_parent(ntg_object_t* object);

#endif // _NTG_OBJECT_H_
