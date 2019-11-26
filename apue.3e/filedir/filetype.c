#include "apue.h"

int
main(int argc, char *argv[])
{
	int		i;
	struct stat	buf;
	char		*ptr;

	for (i = 1; i < argc; i++) 
	{
		printf("%s: ", argv[i]);
		
		if (lstat(argv[i], &buf) < 0) 
		{
			err_ret("lstat error");
			continue;
		}

		if (S_ISREG(buf.st_mode))		// 普通文件
			ptr = "regular";
		else if (S_ISDIR(buf.st_mode))		// 目录文件
			ptr = "directory";
		else if (S_ISCHR(buf.st_mode))		// 字符特殊文件
			ptr = "character special";
		else if (S_ISBLK(buf.st_mode))		// 块特殊文件
			ptr = "block special";
		else if (S_ISFIFO(buf.st_mode))		// 管道或FIFO文件
			ptr = "fifo";
		else if (S_ISLNK(buf.st_mode))		// 链接文件
			ptr = "symbolic link";
		else if (S_ISSOCK(buf.st_mode))		// 套接字
			ptr = "socket";
		else
			ptr = "** unknown mode **";
		
		printf("%s\n", ptr);
	}
	exit(0);
}
