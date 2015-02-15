#include "stack.h"

#define STACK_NR 5
static int stack[STACK_NR];
static int ind;

static int isempty(void)
{
      if (ind == 0) {
	    return 1;//空栈返回1
      }
      return 0;
      return !ind;//可以代替以上几句
}

static int isfull(void)
{
      if (ind == STACK_NR) {
	    return 1;//栈满返回1
      }
      return 0;
      return !(STACK_NR - ind);
}

int push(int data)
{
      if (isfull()) {
	    return -1;
      }

      stack[ind++] = data;//ind始终指向有数据的上一个位置，先入栈再上移
      return 0;
}

int pop(int *data)
{
      if (isempty()) {
	    return -1;
      }

      *data = stack[--ind];
      return 0;
}
