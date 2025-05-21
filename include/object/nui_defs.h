#ifndef _NUI_DEFS_H_
#define _NUI_DEFS_H_

/* This header should only be included when using composition to create a new
 * NUI Object. */
#ifndef _NUI_ALLOW_DEFINES_
// #error "This file only meant to be included in special cases."
#endif // _NUI_ALLOW_DEFINES_

struct _nui_object
{
    struct _nui_container* _parent;
};

struct _nui_container
{
    struct _nui_object _base;
};

struct _nui_pane
{
    struct _nui_object _base;
};

#endif // _NUI_DEFS_H_
