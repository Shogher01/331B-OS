#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t pid;
int status;

pid = fork();

if (pid < 0) {
exit(1);
} else if (pid == 0) {
printf("Child process (PID: %d) running\n", getpid());
sleep(5); 
printf("Child process (PID: %d) is exiting.\n", getpid());
exit(0);
} else {
printf("Parent process (PID: %d) is running.\n", getpid());
wait(&status); 
if (WIFEXITED(status)) {
printf("Parent: Child exited with status %d.\n", WEXITSTATUS(status));
} else {
printf("Parent: Error");
}
printf("Parent process (PID: %d) is exiting.\n", getpid());
}

return 0;
}



