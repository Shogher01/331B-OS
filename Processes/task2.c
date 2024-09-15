#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
pid_t pid1, pid2;
int status;

pid1 = fork();

if (pid1 < 0) {
exit(1);
} else if (pid1 == 0) {
printf("Child process 1 (PID: %d) done\n", getpid());
exit(0);
}

pid2 = fork();

if (pid2 < 0) {
exit(1);
} else if (pid2 == 0) {
printf("Child process 2 (PID: %d) done\n", getpid());
exit(0);
}

if (pid1 > 0 && pid2 > 0) {
waitpid(pid2, &status, 0);
printf("Parent process: Child process 2 finished with status %d\n", WEXITSTATUS(status));

wait(&status);
printf("Parent process: Child process 1 finished with status %d\n", WEXITSTATUS(status));
}

return 0;
}
