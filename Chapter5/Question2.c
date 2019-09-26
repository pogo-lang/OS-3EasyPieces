#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[]){
  int rc = fork();
  int file_des = open("./file_for_2.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  write(file_des, "First Line.\n", strlen("First Line.\n"));

  if(rc == 0){
    printf("-------Child Process------\n");
    write(file_des, "Child Line.\n", strlen("Child Line.\n"));
    printf("File discriptor in child process: %d\n", file_des);
  }else if(rc > 0){
    printf("-------Parent Process-----\n");
    write(file_des, "Parent Line.\n", strlen("Parent Line.\n"));
    printf("File discriptor in parent process: %d\n", file_des);
  }else{
    fprintf(stderr, "Error creating process");
    exit(1);
  }
  FILE *file_pnt;
  file_pnt = fopen("./file_for_2.txt", "r");
  int ch;
  printf("File contents\n");
  while((ch = fgetc(file_pnt)) != EOF){
    printf("%c", ch);
  }
  printf("\n");
  fclose(file_pnt);
  close(file_des);
  return 0;
}

