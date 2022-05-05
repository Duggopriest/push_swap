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

// works but taks too many moves
#include "push_swap.h"

void	printf_stack(t_stacks *sk)
{
	int			i;

	i = sk->lengh + 1;
	system("clear");
	while (--i)
		printf("%d->	| %i 	| %i 	|\n", i, sk->a[i], sk->b[i]);
	printf("-------------------\n");
	printf("    A%d  B%d	Q%d	C%d\n", sk->atop, sk->btop, sk->lengh, sk->current);
	printf("Count	%d / %d Max\n", sk->total, sk->max);
	usleep(1000000);
}

void	sort_long(t_stacks *sk)
{
	int	i;
	int	j;

	i = 0;
	while(i++ < sk->lengh)
	{
		j = sk->current++;
		while (j--)
		{
			top_checka(sk);
			top_swapb(sk);
		}
		rev_sort(sk);
	}
	pushb(sk);
}

void	int_stacks(t_stacks *sk)
{
	int	*a;
	int	*b;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	i = 0;
	while (i <= sk->lengh)
	{
		a[i] = rand() % 99;
		b[i++] = 0;
	}
	sk->a = a;
	sk->b = b;
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc != 3)
		return (0);
	stack.lengh = ft_atoi(argv[1]);
	stack.atop = stack.lengh;
	stack.btop = 0;
	stack.total = 0;
	stack.current = 0;
	stack.max = ft_atoi(argv[2]);
	int_stacks(&stack);
	//printf_stack(&stack);
	sort_long(&stack);
	printf_stack(&stack);
}
