#ifndef HS_DARR_H
#define HS_DARR_H

typedef struct {
      int size;//每笔数据所占的字节数
      int num;//有几个数据
      char *arr;//实际指向顺序表首地址的指针
} DARR;

typedef void darr_op(void *);
typedef int darr_cmp(const void *, const void *);

DARR *darr_creat(int size);

void darr_destroy(DARR *);

int darr_insert(DARR *, const void *data);

void darr_travel(DARR *, darr_op *);

void *darr_find(DARR *, const void *key, darr_cmp *);

void darr_delet(DARR *, const void *key, darr_cmp *);

#endif
