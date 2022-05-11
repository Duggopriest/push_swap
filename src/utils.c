/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:53 by marvin            #+#    #+#             */
/*   Updated: 2022/05/06 11:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	find_min(t_stacks *sk)
{
	int	i;
	int	min;

	i = -1;
	min = 2147483647;
	while (++i < sk->lengh)
	{
		if (sk->c[i] < min)
			min = sk->c[i];
	}
	return (min);
}

int	find_next_min(t_stacks *sk, int last)
{
	int	i;
	int	min;

	i = -1;
	min = 2147483647;
	while (++i < sk->lengh)
		if (sk->c[i] < min && sk->c[i] > last)
			min = sk->c[i];
	return (min);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	brd;

	num = 0;
	sign = 1;
	brd = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (brd < 1)
			return (brd);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	array_checker(int argc, char **argv)
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
		if (checkoverflow(argv[j]))
		{
			putstr("Error\n");
			exit(1);
		}
	}
	return (0);
}
