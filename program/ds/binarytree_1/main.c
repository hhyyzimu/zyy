/* main.c */
#include <stdio.h>
#include "binarytree.h"
void print_item(link p)
{
        printf("%d\n", p->item);
}
int main()
{
	unsigned char pre_seq[] = { 4, 2, 1, 3, 5, 6};
	unsigned char in_seq[] = { 1, 2, 3, 4, 5, 6};
  link root = tree_init(pre_seq, in_seq, 6);
  pre_order(root, print_item);
  putchar('\n');
  in_order(root, print_item);
  putchar('\n');
  post_order(root, print_item);
  putchar('\n');
  printf("count=%d depth=%d\n", count(root), depth(root));
  destroy(root);
  return 0;
}
