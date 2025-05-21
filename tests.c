#include "nui.h"
#include "nui_shared.h"
#include <stdio.h>
#include <unistd.h>

void* init_gui_func(void* data)
{
    printf("NUI: Sleeping...\n");
    sleep(3);
    printf("NUI: Done\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    nui_status_t _status;

    nui_launch(init_gui_func, NULL, &_status);
    printf("MT: Launched NUI thread - STATUS: %d\n", _status);

    printf("MT: Waiting for NUI thread.\n");
    nui_destroy();
    printf("MT: Done. Exiting.\n");

    return 0;
}
