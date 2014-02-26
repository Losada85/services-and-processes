#include <stdio.h>
#include <stdlib.h>
#include <signals.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int spawn (char* program, char** arg_list){
  pid_t child_pid;

  child_pid=fork();
  if(child_pid !=0)
    //padre
    return child_pid;
  else{
    //hijo
    execvp(program,arg_list);
    fprintf(stderr, "ocurrio un error en execve\n");
    abort();
  }
}
sig_atomic_t child_exit_status;
int contador;
void clean_up_child_process(int signal_number){
  int status;
  wait(&status);
  child_exit_status=status;
  contador++;
}
int main(){
  //FILE *fp;
  //fp=fopen("fichero.txt", "w");
  struct sigaction sigchld_action;
  memset(&sigchld_action, 0, sizeof (sigchld_action));
  sigchld_action.sa_handler = &clean_up_child_process;
  sigaction (SIGCHLD, &sigchld_action, NULL);
  char* arg_list[]={
    "cat",
    ">>",
    "fichero.txt",
    "Maria", 
    "Estefania",
    "Laura",
    "Ivan",
    "Fede",
    "Alex",
    "Cabrera",
    "Victor",
    "David",
    "Ramon",
    "/",
    NULL
   };
if(contador<=1){
 spawn("cat", arg_list);
}
return 0;
}
