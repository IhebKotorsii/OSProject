#ifndef __REQUEST_H__
#include <pthread.h>
#define DEFAULT_BUFFER_TAILLE 1
#define DEFAULT_THREADS 1
struct table{
	int nt;
	int b;
	int pr;
	pthread_t *p;
};
void* thread_respond(void* arg);
void *threadsMaster(void *args);
int bufferMax;
int bufferTaille;
int nThreads;

#endif // __REQUEST_H__
