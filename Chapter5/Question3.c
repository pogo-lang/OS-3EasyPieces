#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main (){
  int rc = fork();
  if(rc < 0){
    fprintf(stderr, "Error occured while creating process");
    exit(1);
  }else if(rc == 0){
    printf("----------Child Process----------\n");
    printf("hello\n");
  }else{
    wait(NULL);
    printf("----------Parent Process---------\n");
    printf("goodbye\n");
  }
  return 0;
}
