#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define KEY 123098
void sem_value(){
  int sem_value = semget(KEY, 0,0);
  printf("sem value is:", semctl(sem_value,0, GETVAL));
}
void create_sem(char *x){
  int sem_value = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0664);
  if(sem_value==-1){
    printf("failed because sem already exists\n");
  }
 else{
    int z;
    scanf(x, "%d", &z);
    semctl(sem_value, 0, SETVAL, z);
    printf("sem created\n");
  }
}

void sem_remove(){
  int sem_value; = semget(KEY,0,0);
  printf("sem removed", semctl(sem_value, 0, IPC_RMID));
}

int main(int c, char ** v){
  if (c< 2){
    printf("failed\n");
  }
  else{
    if(strcmp(v[1], "-r")==0){
      sem_remove();
    }
    if(strcmp(v[1], "-v")==0){
      sem_value();
    }
    if(strcmp(argv[1],"-c")==0 && !(c <3)){
      sem_create(v[2]);
    }
    else {
      printf("failed\n");
    }
  }
  return 0;
}
