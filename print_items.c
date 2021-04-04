#include "ikhane.h"

void			print_items(int *items, int n)
{
	int		i;

	i = 0;
	while (i < n)
		printf("%d ", items[i++]);
	printf("\n");
}
