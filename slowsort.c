#include "ikhane.h"

void		slowsort(int items[], int i, int j)
{
	int		mid;

	if (i >= j)
		return ;
	mid = i + (j - i) / 2;
	slowsort(items, i, mid);
	slowsort(items, mid + 1, j);
	if (items[j] < items[mid])
		swap(&items[j], &items[mid]);
	slowsort(items, i, j - 1);
}

int			main(void)
{
	int		items[] = {6, 1, 3, 5, 7, 9, 0};
	int		n = sizeof(items) / sizeof(items[0]);

	print_items(items, n);
	slowsort(items, 0, n - 1);
	print_items(items, n);
}
