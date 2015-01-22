#include <stdio.h>
#include "para_callback.h"

void say_hello(void *str)
{
	printf("Hello %s\n", (const char *)str);
}

void count_numbers(void *num)
