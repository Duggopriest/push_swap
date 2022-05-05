/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:31:10 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 12:51:51 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bit(t_stacks *sk)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
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