#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void sigcont_handler(int signum){
  printf("goodbye\n");
}

int main(int argc, char const *argv[]){
  int parent_id = getpid();
  int rc = fork();
  struct sigaction act;
  act.sa_handler = sigcont_handler;

  if(rc<0){
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0){
    kill(parent_id, SIGCONT);
    printf("Hello\n");
  }else{
    sigaction(SIGCONT, &act, NULL);
    pause();
  }
  return 0;
}
