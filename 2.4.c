#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
int main(void) {
  for(int i = 1; i < 5; i++) {
    pid_t pid = fork();
 
    if(pid == 0) {
      printf("Child process => PPID=%d, PID=%d\n", getppid(), getpid());
      exit(0);
    }
    else  {
      printf("Parent process => PID=%d\n", getpid());
      printf("Waiting for child processes to finish...\n");
      wait(NULL);
      printf("Job is done\n");
    }
  }
 
  return EXIT_SUCCESS;
}


