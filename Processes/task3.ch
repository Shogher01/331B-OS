#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_exit(void) {
time_t now;
time(&now);
printf("Program exited at: %s\n", ctime(&now));
}

void clean_up(void){
printf("Cleanup process\n");
}

int main() {
atexit(log_exit);
atexit(clean_up);
//exit(0);
printf("Program is running\n");
exit(0);
printf("Something\n");


return 0;
}
