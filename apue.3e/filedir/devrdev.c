#include "apue.h"
#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

int
main(int argc, char *argv[])
{
	int			i;
	struct stat	buf;

	for (i = 1; i < argc; i++) {
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			err_ret("stat error");
			continue;
		}

		printf("dev = %ld/%ld", buf.st_dev,  buf.st_dev);

		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf(" (%s) rdev = %ld/%ld",
					(S_ISCHR(buf.st_mode)) ? "character" : "block",
					buf.st_rdev, buf.st_rdev);
		}
		printf("\n");
	}

	exit(0);
}

