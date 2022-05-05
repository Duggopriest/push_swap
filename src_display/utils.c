/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:03:32 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 14:01:51 by jgobbett         ###   ########.fr       */
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

int	is_solved(t_stacks *sk)
{
	int	i;

	i = -1;
	while (++i < sk->lengh && sk->atop == sk->lengh)
		if (sk->a[i] > sk->a[i + 1])
			return (0);
	return (i);
}

int	find_min(t_stacks *sk)
{
	int	i;
	int	min;
	int	max;

	i = 1;
	max = 0;
	while (++i < sk->lengh)
		if (sk->c[i] > max)
			max = sk->c[i];
	i = 1;
	min = max;
	while (++i < sk->lengh)
		if (sk->c[i] < min)
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