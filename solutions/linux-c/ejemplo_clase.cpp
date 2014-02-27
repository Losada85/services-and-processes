#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

//./nombre_programa 2 > fichero.log -->guardar el bufer de errores en un fichero
//tail -f  fichero.log --> muestra el contenido del fichero sin cerrarlo

sig_atomic_t times;
void handler(int signal_number){
   times++;
fprintf(stderr, "Signal %i received. \n", signal_number);
}

int main (int argc, char* argv[]){
struct digaction sa;
memset (&sigchld_action, 0, sizeof(sa));//para poder acceder a todos los valores de la estructura y ponerlos a 0
sa.sa_handler=&handler;
sigaction (SIGINT, &sa, NULL);

for(;;) // bucle infinito 
    printf("%i\n", (int) times);

return EXIT_SUCCESS;
}
