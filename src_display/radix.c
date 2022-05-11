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