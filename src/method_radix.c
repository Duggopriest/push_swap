/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:31:10 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 16:05:59 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_solved(t_stacks *sk)
{
	int	i;

	i = -1;
	while (++i < sk->lengh && sk->atop == sk->lengh)
		if (sk->a[i] > sk->a[i + 1])
			return (0);
	return (i);
}

void	sort_bit(t_stacks *sk)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
	printf("sortting\n");
	printf_stack(sk);
	while (!is_solved(sk))
	{
		j = sk->atop;
		while (j--)
		{
			b = sk->a[sk->atop];
			if (b & (1 << i))
				pusha(sk);
			else
				rotatea(sk);
		}
		while (sk->btop)
			pushb(sk);
		i++;
	}
}