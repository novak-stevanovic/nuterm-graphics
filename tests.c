#include "ntg.h"
#include <stdio.h>
#include <unistd.h>

void init_gui_func(void* data)
{
    printf("\rNTG: Sleeping...\n");
    sleep(3);
    printf("\rNTG: Done\n");
    return;
}

int main(int argc, char *argv[])
{
    ntg_status_t _status;

    ntg_launch(init_gui_func, NULL, &_status);
    printf("\rMT: Launched NTG thread - STATUS: %d\n", _status);

    printf("\rMT: Waiting for NTG thread.\n");
    ntg_destroy();
    printf("\rMT: Done. Exiting.\n");

    // int n1[] = { 1, 2 };
    // int* n2 = { 1, 2 };
    //
    return 0;
}
