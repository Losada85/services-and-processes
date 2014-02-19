#include <stdio.h>
#include <unistd.h>
int main(){
	printf("This is the process number %d\n", (int) getpid());
	printf("The number of the parent process is %d\n", (int)getppid());

return 0;
}

