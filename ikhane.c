#include "ikhane.h"
#include <stdlib.h>

typedef struct		s_stack
{
	int				*num;
	int				size;
	int				top;
}					t_stack;

int				is_empty(t_stack *s)
{
	if (s->top == -1)
		return (1);
	else
		return (0);
}

int				is_full(t_stack *s)
{
	if (s->top == s->size - 1)
		return (1);
	else
		return (0);
}

int				push(int n, t_stack *s)
{
	printf("\nPUSH %d\n", n);
	if (is_full(s))
		return (0);
	s->top++;
	s->num[s->top] = n;
	return (n);
}

int			pop(t_stack *s)
{
	int	tmp;

	printf("\nPOP");
	if (is_empty(s))
		return (0);
	tmp = s->num[s->top];
	s->top--;
	return (tmp);
}

void	show(t_stack *s)
{
	int	i;

	i = s->top;
	while (i >= 0)
		printf("|%d|\n", s->num[i--]);	
}

void			cpy(t_stack *s, char **av)
{
	int		i;

	i = 0;
	while (i < s->size)
		push(atoi(av[i++ + 1]), s);
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac <= 1)
		return (0);
	a = (t_stack){(int *)malloc(sizeof(int) * (ac - 1)), ac - 1, -1};
	b = (t_stack){(int *)malloc(sizeof(int) * (ac - 1)), ac - 1, -1};
	cpy(&a, av);
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	push(12, &a);
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
	printf(" %d\n", pop(&a));
	show(&a);
}
