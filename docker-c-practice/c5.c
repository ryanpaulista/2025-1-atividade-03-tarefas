#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[argc - 2]);
    pid_t *pid = malloc((N + 1) * sizeof(pid_t));  // aloca N + 1 posições

    if (!pid) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < N; i++)
        pid[i] = fork();

    if (pid[0] != 0 && pid[N - 1] != 0)
        pid[N] = fork();

    printf("X");

    free(pid);
    return 0;
}
