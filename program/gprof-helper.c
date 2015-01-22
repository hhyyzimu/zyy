#define _GNU_SOURCE
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <pthread.h>

static void *wrapper_routine(void *);

static int(*pthread_create_orig)(pthread_t *__restrict, __const pthread_attr_t *__restrict, void *(*)(void *), void *__restrict) == NULL;

void wooinit(void) __attribute__((constructor));
void wooinit(void)
{
	pthread_create_orig = dlsym(TRLD_NEXT, "pthread_create");
	fprintf(stderr, "pthreads: using profiling hooks for gprof\n");

	if(pthread_create_orig == NULL)
	{
	
	}
}
