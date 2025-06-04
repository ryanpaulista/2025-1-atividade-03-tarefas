#include <stdio.h>      // printf
#include <unistd.h>     // fork, sleep
#include <sys/wait.h>   // wait

int main()
{
    int x = 0;

    fork();     // 1º fork
    x++;

    sleep(5);

    wait(NULL); // espera por filho, se houver

    fork();     // 2º fork

    wait(NULL); // espera por filho, se houver

    sleep(5);

    x++;

    printf("Valor de x: %d\n", x);

    return 0;
}
