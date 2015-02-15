#include <stdlib.h>
#include <string.h>

#include "darr.h"

#if 0
typedef struct {
      int size;
      int num;
      char *arr;//实际指向顺序表首地址的指针
} DARR;
typedef void darr_op(void *);
#endif

DARR *darr_creat(int size)
{
      DARR *new;

      new = malloc(sizeof(*new));
      if (new == NULL) {
	    return NULL;
      }

      new->size = size;
      new->num = 0;
      new->arr = NULL;

      return new;
}

void darr_destroy(DARR *ptr)
{
      free(ptr->arr);
      free(ptr);
}

int darr_insert(DARR *ptr, const void *data)
{
      void *tmp;

      tmp = realloc(ptr->arr, ptr->size * (ptr->num + 1));
      if (tmp == NULL) {
	    return -1;
      }
      ptr->arr = tmp;

      memcpy(ptr->arr + ptr->num * ptr->size, data, ptr->size);
      ptr->num++;

      return 0;
}

void darr_travel(DARR *ptr, darr_op *op)
{
      int i;

      for (i = 0; i < ptr->num; i++) {
	    op(ptr->arr + ptr->size * i);
      }
}

static int find__(DARR *ptr, const void *key, darr_cmp *cmp)//内部查找
{
      int i;

      for (i = 0; i < ptr->num; i++) {
	    if (cmp(key, ptr->arr + ptr->size * i) == 0) {
		  return i;
	    }
      }

      return -1;
}

void *darr_find(DARR *ptr, const void *key, darr_cmp *cmp)
{
      int ind;

      ind = find__(ptr, key, cmp);
      if (ind == -1) {
	    return NULL;
      }

      return ptr->arr + ptr->size * ind;
}

void darr_delet(DARR *ptr, const void *key, darr_cmp *cmp)
{
      int ind;

      ind = find__(ptr, key, cmp);
      if (ind == -1) {
	    return;
      }

      memmove(ptr->arr + ptr->size * ind,
			  ptr->arr + ptr->size * (ind + 1),
			  ptr->size * (ptr->num - ind - 1));
      ptr->num--;
      ptr->arr = realloc(ptr->arr, ptr->size * ptr->num);
      if (ptr->num == 0) {
	    ptr->arr = NULL;
      }
}
