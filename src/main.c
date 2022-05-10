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
	//array_no_rep(sk);
	make_sequential(sk);
}

void	top_checka(t_stacks *sk)
{
	if (sk->a[sk->atop] > sk->a[sk->atop - 1])
		swapa(sk);
	exit(0);
}

int	ft_array_isnumb(int argc, char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] < '0' || argv[j][i] > '9') && argv[j][i] != '-')
			{
				putstr("Error\n");
				exit(1);
			}
			i++;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	sk;

	sk.lengh = argc - 1;
	sk.total = 0;
	sk.btop = -1;
	sk.atop = sk.lengh - 1;
	//ft_array_isnumb(argc, argv);
	//printf("is num\n");
	int_stacks(&sk, argv);
	if (argc == 2 || is_solved(&sk))
		return (0);
	else if (argc == 3)
		top_checka(&sk);
	else if (argc == 4)
		sort_3(&sk);
	else if (argc == 6)
		sort_5(&sk);
	else
		radix(&sk);
}