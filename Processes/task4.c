#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
pid_t pid1, pid2;
int status;

pid1 = fork();

if (pid1 < 0) {
exit(1);
} else if (pid1 == 0) {
printf("Child 1 (PID: %d), exit code: 17.\n", getpid());
        exit(17); 
}

pid2 = fork();

if (pid2 < 0) {
exit(1);
} else if (pid2 == 0) {
printf("Child 2 (PID: %d),exit code: 18.\n", getpid());
exit(18);
}

waitpid(pid1, &status, 0);
if (WIFEXITED(status)) {
printf("Parent: Child 1 exited with status %d.\n", WEXITSTATUS(status)); 
} else {
printf("Error.\n");
}

waitpid(pid2, &status, 0);
if (WIFEXITED(status)) {
printf("Parent: Child 2 exited with status %d.\n", WEXITSTATUS(status));
}else {
printf("Error.\n");
}
return 0;
}









