/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:03:32 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 16:05:50 by jgobbett         ###   ########.fr       */
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
	int	max;

	i = -1;
	max = 0;
	while (++i < sk->lengh)
		if (sk->a[i] > max)
			max = sk->a[i];
	i = -1;
	min = max;
	while (++i < 5)
		if (sk->a[i] < min)
			min = sk->a[i];
	return (min);
}

int	find_next_min(t_stacks *sk, int last)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	max = 0;
	while (++i < sk->lengh)
		if (sk->a[i] > max)
			max = sk->a[i];
	i = -1;
	min = max;
	while (++i < 5)
		if (sk->a[i] <= min && sk->a[i] > last)
			min = sk->a[i];
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
		while (argv[j][i])
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (1);
	return (0);
}