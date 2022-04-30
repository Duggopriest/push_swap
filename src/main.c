/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 07:56:54 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_stack(t_stacks *sk)
{
	int			i;
	static int	c = 0;

	i = sk->lengh + 1;
	system("clear");
	while (--i)
		printf("%d->| %i | %i |\n", i, sk->a[i], sk->b[i]);
	printf("-------------------\n");
	printf("    A%d  B%d	Q%d\n", sk->atop, sk->btop, sk->lengh);
	printf("Count	%d\n", c++);
}

void	sort(t_stacks *sk)
{
	int	i;
	int	j;

	i = 0;
	while (i++ < sk->lengh)
	{
		j = sk->current++;
		rev_sort(sk);
		while (j--)
		{
			top_checka(sk);
			top_swapb(sk);
		}
	}
	rev_sort(sk);
	pushb(sk);
}

void	int_stacks(t_stacks *sk, char **argv)
{
	int	*a;
	int	*b;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	printf("malloced a-b\n");
	i = 0;
	while (i <= sk->lengh)
	{
		a[i] = ft_atoi(argv[i]);
		b[i++] = 0;
	}
	sk->a = a;
	sk->b = b;
	printf("inilised stacks\n");
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	stack.lengh = argc - 1;
	stack.atop = argc - 1;
	stack.btop = 0;
	int_stacks(&stack, argv);
	printf_stack(&stack);
	sort(&stack);
	printf_stack(&stack);
}
