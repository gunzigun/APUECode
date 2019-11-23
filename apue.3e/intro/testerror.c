#include "apue.h"
#include <errno.h>

int
main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));  //基于EACCES产生一条错误信息
	errno = ENOENT;
	perror(argv[0]);			      // 基于当前的erron产生错误信息
	exit(0);
}
