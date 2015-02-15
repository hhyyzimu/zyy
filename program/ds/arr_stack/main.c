#include <stdio.h>

#include "stack.h"

int main(void)
{
      int arr[] = {3,2,1,6,7,9,8,5,4};
      int i;
      int data;
      int ret;

      for (i = 0; i < 9; i++) {
	    ret = push(arr[i]);
	    if (ret == -1) {
		  printf("stack full.\n");
		  break;
	    }
      }

      for (i = 0; i < 9; i++) {
	    ret = pop(&data);
	    if (ret == -1) {
		  printf("stack empty.");
		  break;
	    }
	    printf("%d ", data);
      }
      printf("\n");

      return 0;
}
