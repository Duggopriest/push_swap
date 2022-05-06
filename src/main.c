/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:36:50 by marvin            #+#    #+#             */
/*   Updated: 2022/05/06 11:36:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *sk)
{
	int	i;

	i = -1;
	//system("clear");
	while (++i < sk->lengh)
		printf("%d	->| %d 	| %d 	| %d |\n", i + 1, sk->a[i], sk->b[i], sk->c[i]);
	printf("----------------------\n");
	printf("Q%d A%d   B%d   M%d	B%d\n", sk->lengh, sk->atop, sk->btop, sk->total, sk->bit);
	//usleep(800000);
}

void	make_sequential(t_stacks *sk)
{
	int	min;
	int	i;
	int	j;

	min = find_min(sk);
	i = 0;
	j = 1;
	while (j <= sk->lengh)
	{
		if (min == sk->c[i])
		{
			sk->a[i] = j++;
			min = find_next_min(sk, min);
			i = -1;
		}
		i++;
	}
}

void	int_stacks(t_stacks *sk, char **argv)
{
	int *a;
	int	*b;
	int	*c;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	c = malloc(sizeof(int) * sk->lengh);
	i = 0;
	while (i < sk->lengh)
	{
		a[i] = 0;
		b[i] = 0;
		c[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sk->a = a;
	sk->b = b;
	sk->c = c;
	make_sequential(sk);
	print_stacks(sk);
}

int	main(int argc, char **argv)
{
	t_stacks sk;

	sk.lengh = argc - 1;
	sk.total = 0;
	sk.btop = -1;
	sk.atop = sk.lengh - 1;
	int_stacks(&sk, argv);
	print_stacks(&sk);
	radix(&sk);
	print_stacks(&sk);
}