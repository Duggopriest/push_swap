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
	int	*a;
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
		b[i] = -999999;
		c[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	sk->a = a;
	sk->b = b;
	sk->c = c;
	array_no_rep(sk);
	make_sequential(sk);
}

void	top_checka(t_stacks *sk)
{
	if (sk->a[1] < sk->a[0])
		swapa(sk);
	exit(0);
}

void	free_stacks(t_stacks *sk)
{
	void	*temp;

	temp = sk->a;
	free(temp);
	temp = sk->b;
	free(temp);
	temp = sk->c;
	free(temp);
}

int	main(int argc, char **argv)
{
	t_stacks	sk;

	sk.lengh = argc - 1;
	sk.total = 0;
	sk.btop = -1;
	sk.atop = sk.lengh - 1;
	int_stacks(&sk, argv);
	array_checker(argc, argv);
	if (argc <= 2 || is_solved(&sk))
		return (0);
	else if (argc == 3)
		top_checka(&sk);
	else if (argc == 4)
		sort_3(&sk);
	else if (argc == 6)
		sort_5(&sk);
	else
		radix(&sk);
	free_stacks(&sk);
}
