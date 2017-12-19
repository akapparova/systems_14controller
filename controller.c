#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>

#define KEY 67

void create_sem(int value){

  int id = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0664);

  if (id==  -1) 
    printf("Semaphore already exists  \n");
  

  else{
    semctl(id, 0, SETVAL, value);
    printf("Semaphore created [%d] with value %d  \n", id, value);
  }
}

void view_sem(){

  int n = semget(KEY, 1, 0664);
  if (n== -1) {
    printf("Semaphore doesn't exist  \n");
  }
  else {
    printf("Semaphore %d's value is %d \n", n, (semctl (n, 0, GETVAL))   );
  }
}




void remove_sem(){
  int d = semget(KEY, 1, 0664);

  if(d== -1)
    printf("Semaphore doesnt exist  \n");


  else{
    printf("Semaphore successfully removed %d \n", semctl( d, 1, IPC_RMID));   
  }
}




int main(int argc, char ** argv){	
  if (strcmp(argv[1], "-c") == 0){
    create_sem(atoi(argv[2]));
  }
  else if (strcmp(argv[1],   "-v") ==0){
    view_sem();
  }
  else if (strcmp(argv[1], "-r")== 0){
    remove_sem();
  }
}
