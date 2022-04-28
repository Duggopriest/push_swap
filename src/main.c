/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/28 17:22:26 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_stack(t_int *stack_A, t_int *stack_B)
{
	int	i;

	i = 9;
	printf("\n");
	while (--i)
		printf("%d->| %c | %c |\n", i, stack_A->stack[i][0], stack_B->stack[i][0]);
	printf("---------------------------\n");
	printf(" A	 B		Q%d\n", stack_A->lengh);
}

char	*char_calloc(int size)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(size);
	while (i < size)
		new[i++] = '0';
	new[i] = '\0';
	return (new);
}

char **new_col(int size)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(size + 1);
	while (i < size)
		new[i++] = char_calloc(1);
	new[i] = 0;
	new[0][0] = '0';
	new[1][0] = '0';
	new[2][0] = '0';
	new[3][0] = '0';
	return (new);
}

void	swaptop(t_int *a)
{
	char	*temp;

	temp = a->stack[a->top];
	a->stack[a->top] = a->stack[a->top - 1];
	a->stack[a->top - 1] = temp;
}

void	push(t_int *from, t_int *to)
{
	char	*temp;

	temp = from->stack[from->top];
	from->stack[from->top] = to->stack[to->top];
	from->top--;
	to->top++;
	to->stack[to->top] = temp;
}

void	sort(t_int *a, t_int *b)
{
	// int	i;
	//swaptop(a);
	push(a, b);
	// i = 1;
	// while (i)
	// {
	// 	if (a->stack[a->top] > )
	// }
}

int	main(int argc, char **argv)
{
	t_stacks stack;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stacks));
	a->lengh = argc - 1;
	a->top = argc - 2;
	b->top = 0;
	stack = &argv[1];
	b->stack = new_col(argc - 1);
	while (i++ < 3)
	{
		printf_stack(a, b);
		sort(a, b);
	}
}