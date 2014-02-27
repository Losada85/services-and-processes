#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
	++sigusr1_count;
}


int spawn(char*  program, char** arg_list)
{
	pid_t child_pid;
	sig_atomic_t sigusr1_count = 0;

	child_pid = fork();
	if(chid_pid !=0 )
		return child_pid;
	else{
		execvp (program, arg_list);
		fprintf(stderr, "an error ocurred in execvp\n");
		abort();
	}
}

int main()
{
	char* arg_list[] = {
		"cat",
		">",
		"mery",
		NULL
	};
	struct signaction sa;
	memset (&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	signation (SIGUSR1, &SA, NULL);

	/*AKI HAY QUE HACER EL CODIGO*/

	printf(SIGUSR1 was raised %d times\n", sigurs1_count);
	

	spawn ("cat", arg_list);

	printf("hecho");
	return 0;
}
