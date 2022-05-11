/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:11:17 by marvin            #+#    #+#             */
/*   Updated: 2022/05/06 12:11:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_solved(t_stacks *sk)
{
	int	i;

	i = -1;
	while (++i < sk->lengh - 1 && sk->atop == sk->lengh - 1)
		if (sk->a[i] > sk->a[i + 1])
			return (0);
	return (i);
}

void	radix(t_stacks *sk)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
	while (!is_solved(sk))
	{
		sk->bit = i;
		j = sk->atop;
		while (j-- >= 0)
		{
			b = sk->a[0];
			if (!(b & (1 << i)))
				pushb(sk);
			else
				rotatea(sk);
		}
		while (sk->btop >= 0)
			pusha(sk);
		i++;
	}
}

void	array_no_rep(t_stacks *sk)
{
	int	i;
	int	j;

	j = -1;
	while (++j < sk->lengh)
	{
		i = 0;
		while (i < sk->lengh)
		{
			if (sk->c[j] == sk->b[i++] && i != j)
			{
				free_stacks(sk);
				putstr("Error");
				exit(0);
			}
		}
		sk->b[j] = sk->c[j];
	}
	i = 0;
	while (++i < sk->lengh)
		sk->b[i] = 0;
}

int	checkoverflow(char *str)
{
	long	result;
	int		sign;
	char	*s;

	s = str;
	sign = 1;
	result = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		result = 10 * result + *s - '0';
		s++;
	}
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		return (1);
	return (0);
}
