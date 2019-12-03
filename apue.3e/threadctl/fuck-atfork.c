#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
 
 
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
 
void *doit(void *arg)
{
	printf("pid = %d begin doit ...\n", getpid());
	pthread_mutex_lock(&mutex);
	struct timespec ts = {10, 0};
	nanosleep(&ts, NULL);
	pthread_mutex_unlock(&mutex);
	printf("pid = %d end doit ...\n", getpid());
	return NULL;
}

void *doitchild(void *arg)
{
	printf("pid = %d begin doit ...\n", getpid());
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
	printf("pid = %d end doit ...\n", getpid());
	return NULL;
}

 
void prepare(void)
{
	printf("11111111\n");
	pthread_mutex_unlock(&mutex);
}
 
void parent(void)
{
	printf("22222222\n");
	pthread_mutex_lock(&mutex);
}
 
int main(void)
{
	pthread_atfork(prepare, parent, NULL);
	printf("pid = %d Entering main ...\n", getpid());
	pthread_t tid;
	pthread_create(&tid, NULL, doit, NULL);
	struct timespec ts = {1, 0};
	nanosleep(&ts, NULL);
	if (fork() == 0)
	{
		doitchild(NULL);
	}
	pthread_join(tid, NULL);
	printf("pid = %d Exiting main ...\n", getpid());
					     
	return 0;
}
