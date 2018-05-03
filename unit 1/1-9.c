#include "apue.h"
#include <sys/wait.h>
#define MAXLINE 4096
static void sig_int(int);
int main()
{
	char buf[MAXLINE];
	pid_t pid;
	int satus;
	if(signal(SIGINT,sig_int)==SIG_ERR)
		err_sys("signal error");
	printf("%%");
	while(fgets(buf,MAXLINE,stdin)!=NULL)
	{
		if(buf[strlen(buf)-1]=='\n')
			buf[strlen(buf)-1]=0;
	
		if((pid=fork())<0)
			err_sys("fock error");
		else if(pid==0)
		{
			execlp(buf,buf,(char *)0);
			err_sys("couldn't execute buf");
			exit(127);
		}
	
		if((pid=waitpid(pid,&satus,0))<0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
void sig_int(int signo)
{
	printf("interrupt\n%% ");
}
