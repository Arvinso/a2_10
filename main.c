
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

int main()
{
	pid_t pid, sid;
	pid = fork();

	if(pid < 0)
	{
		perror("pid");
		exit(EXIT_FAILURE);
	}

	printf("pid: %d", pid);

	if(pid > 0)
	{
		exit(EXIT_SUCCESS);
	}

	sid = setsid();

	if(sid < 0)
	{
		perror("sid");
		exit(EXIT_FAILURE);
	}

	printf("sid: %d", sid);

	time_t	starttime;
	time_t	nowtime;

	time(&starttime);
	time(&nowtime);

	while(nowtime - starttime < 20)
	{
		time(&nowtime);
	}

	return 0;
}

