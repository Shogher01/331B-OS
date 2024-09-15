#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
pid_t pid;
pid = fork();

if(pid > 0){
printf("Parent process: %d\n", getpid());
return 0;
}else if(pid==0){
printf("Child process: %d\n", getpid());
return 0;
}else {
return 1;
};

}
