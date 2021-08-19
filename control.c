#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

static volatile sig_atomic_t keep_running = 1;

static void sig_handler(int _)
{
    (void)_;
    keep_running = 0;
}

int main(void)
{
    int i = 0;
    i = signal(SIGINT, sig_handler);

    while (keep_running)
        ;

    printf("%d\n", i);
    return EXIT_SUCCESS;
}