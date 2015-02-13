#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE		5

int main(void)
{
	int i, j, temp, flag;
	int arr[MAXSIZE] = {12, 34, 23, 1, 5};

	for(i = 0; i < MAXSIZE - 1; i++){
		flag = 0;
		for(j = 0; j < MAXSIZE-1-i; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = 1;
			}
		}
		if(flag == 0){
			break;
		}
	}

	for(i = 0; i < MAXSIZE; i++)
		printf("%d\t", arr[i]);
	printf("\n");

	exit(0);
}
