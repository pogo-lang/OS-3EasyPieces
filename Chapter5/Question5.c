#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const* argv[]){
  int rc = fork();
  if(rc<0){
    fprintf(stderr,"fork failed");
  }else if(rc == 0){
    pid_t wait_return = wait(NULL);
    printf("child wait return %d\n", wait_return);
  }else{
    pid_t wait_return = wait(NULL);
    printf("parent wait return %d\n", wait_return);
  }
  return 0;
}
