#include "queue.h"

#define QUEUE_NR 1024
enum {QUNEMPTY, QUNFULL};//枚举作标记，两个参数相当于0，1

static int queue[QUEUE_NR];
static int ind_e, ind_d;
static int flag = QUNFULL;

static int isfull(void)
{
      if (ind_e == ind_d && flag == QUNEMPTY) {//上次操作是入队
	    return 1;//队满返回1
      }
      return 0;
}

static int isempty(void)
{
      if (ind_e == ind_d && flag == QUNFULL) {
	    return 1;
      }
      return 0;
}

int enq(int data)//入队
{
      if (isfull()) {//入队判断是否队满
	    return -1;
      }

      queue[ind_e++] = data;//先存数据，尾巴加1
      if (ind_e == QUEUE_NR) {//如果下标等于数组个数，让下标返回0
	    ind_e = 0;
      }
      flag = QUNEMPTY;

      return 0;
}

int deq(int *data)
{
      if (isempty()) {
	    return -1;
      }

      *data = queue[ind_d++];
      if (ind_d == QUEUE_NR) {
	    ind_d = 0;
      }
      flag = QUNFULL;

      return 0;
}
