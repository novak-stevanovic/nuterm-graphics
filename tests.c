#include "ng.h"
#include "ng_shared.h"
#include <stdio.h>
#include <unistd.h>

void* init_gui_func(void* data)
{
    printf("\rNG: Sleeping...\n");
    sleep(3);
    printf("\rNG: Done\n");
    return NULL;
}

int main(int argc, char *argv[])
{
    ng_status_t _status;

    ng_launch(init_gui_func, NULL, &_status);
    printf("\rMT: Launched NG thread - STATUS: %d\n", _status);

    printf("\rMT: Waiting for NG thread.\n");
    ng_destroy();
    printf("\rMT: Done. Exiting.\n");

    return 0;
}
