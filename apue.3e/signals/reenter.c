#include "apue.h"
#include <pwd.h>

static void
my_alarm(int signo)
{
	struct passwd	*rootptr;

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)
			err_sys("getpwnam(root) error");
	alarm(1);
}

int
main(void)
{
	struct passwd	*ptr;

	signal(SIGALRM, my_alarm);
	
	printf("before alarm\n");
	
	alarm(1);
	
	printf("after alarm\n");
	
	int a = 0;
	for ( ; ; ) 
	{
		if (a > 3)
			continue;

		printf("fuck problem!\n");
		
		if ((ptr = getpwnam("xuguanglong")) == NULL)
			err_sys("getpwnam error");
		if (strcmp(ptr->pw_name, "xuguanglong") != 0)
			printf("return value corrupted!, pw_name = %s\n",
					ptr->pw_name);
		++a;
	}
}
