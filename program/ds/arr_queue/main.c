/*顺序队列*/
#include <stdio.h>

#include "queue.h"

int main(void)
{
      int arr[] = {3,2,1,6,7,5,6,7,8,9};
      int i, j;
      int ret;
      int data;

      for (j = 0; j < 7; j++) {
	    for (i = 0; i < 2; i++) {
		  ret = enq(arr[i]);
		  if (ret == -1) {
			printf("queue full.\n");
			break;
		  }
	    }

	    for (i = 0; i < 7; i++) {
		  ret = deq(&data);
		  if (ret == -1) {
			printf("\nqueue empty.");
			break;
		  } else {
			printf("%d ", data);
		  }
	    }
	    printf("\n");
      }

      return 0;
}
