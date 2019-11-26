#include <apue.h>
#include <fcntl.h>
 
int main(int argc, char *argv[])
{
       	if(3 != argc)
	{
		printf("reference error!\n");
		exit(0);
	}
	     
	int res;
	res = link(argv[1], argv[2]);
		     
	if(res)
	{
		printf("link error!\n");
	}
			 
	return 0;
}
