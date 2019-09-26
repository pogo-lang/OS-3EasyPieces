#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int x;
  x = 100;
  int rc = fork();
  if(rc == 0){
    printf("------Child Process------\n");
    printf("Value of x in child process %d\n", x);
    x = 200;
    printf("New Value of x in child process %d\n", x);
  }else if(rc > 0){
    printf("------Parent Process------\n");
    printf("Value of x in parent process %d\n", x);
    x = 300;
    printf("New Value of x in parent process %d\n", x);
  }else{
    fprintf(stderr,"Error creating process\n");
    exit(1);
  }
  return 0;
}
