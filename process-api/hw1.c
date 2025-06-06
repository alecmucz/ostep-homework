#include <unistd.h>
#include <stdio.h>

int main(){

  pid_t pid;
  int x = 100;

  pid = fork();

  switch(pid){
    case -1:
      perror("Fork Failure");
      break;
    case 0:
      x=200;
      printf("Child PID(%d): %d\n",getpid(),x);
      break;
    default:
      x=300;
      printf("Parent PID(%d): %d\n",getpid(),x);
  }

  return 0;

}

/* 
*  1a. The value of x within the child process is 100.
*
*  1b. Each process is able to independently change its variable.
*
*  Conclusion : After fork(), both processes have seperate copies
*  of the x variable, which is inline with the idea that a child process 
*  gets a new but a duplicate memory space based on its parent.
*
*/
