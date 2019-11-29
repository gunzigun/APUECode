#include "apue.h"

static void charatatime(char *);

int
main(void)
{
	pid_t	pid;

	TELL_WAIT();			/* set things up for TELL_xxx & WAIT_xxx */

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		WAIT_PARENT();		/* wait parent done! */
		charatatime("output from child\n");
	} else {
		charatatime("output from parent\n");
		TELL_CHILD(pid);        /* tell child we are done! */
	}
	exit(0);
}

static void
charatatime(char *str)
{
	char	*ptr;
	int		c;

	setbuf(stdout, NULL);			/* set unbuffered */
	for (ptr = str; (c = *ptr++) != 0; )
		putc(c, stdout);
}
