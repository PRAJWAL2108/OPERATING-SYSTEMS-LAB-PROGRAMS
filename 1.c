#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	int pid;
	pid = fork();
	if(pid<0)
	{
		printf("\n Fork failed \n");
		exit(1);
	}
	else if(pid==0)
	{
		execlp("ls","ls", NULL);
		exit(0);
	}
	else
	{
		printf("\n I am a parent, the child just ended \n");
		wait(NULL);
	}
	return 0;
}
