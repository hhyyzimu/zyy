#include <stdio.h>

#include "darr.h"

#define NAMESIZE 32

struct score {
      int id;
      char name[NAMESIZE];
      int math;
};

void print_s(void *data)
{
      struct score *d = data;
      printf("%d %s %d\n", d->id, d->name, d->math);
}

int id_cmp(const void *key, const void *record)
{
      const int *id = key;
      const struct score *r = record;

      return *id - r->id;
}

int main(void)
{
      struct score tmp, *datap;
      int i, id;
      DARR *arr;

      arr = darr_creat(sizeof(struct score));

      for (i = 0; i < 7; i++) {
	    tmp.id = i;
	    tmp.math = 100 - i;
	    snprintf(tmp.name, NAMESIZE, "stu%d", i);

	    darr_insert(arr, &tmp);
      }

      darr_travel(arr, print_s);

      id = 3;
      darr_delet(arr, &id, id_cmp);
      printf("\n");
      darr_travel(arr, print_s);
#if 0
      id = 7;
      datap = darr_find(arr, &id, id_cmp);
      if (datap == NULL) {
	    printf("Can not find.\n");
      } else {
	    print_s(datap);
      }
#endif
      darr_destroy(arr);

      return 0;
}
