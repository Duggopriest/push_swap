/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 05:41:13 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 07:42:11 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_checka(t_stacks *sk)
{
	if (sk->atop > 0)
	{
		if (sk->a[sk->atop] < sk->a[sk->atop - 1])
			swapa(sk);
		pusha(sk);
	}
}

void	top_checkb(t_stacks *sk)
{
	if (sk->btop > 0)
	{
		if (sk->b[sk->btop] > sk->b[sk->btop - 1])
			swapb(sk);
		pushb(sk);
	}
}

void	top_swapa(t_stacks *sk)
{
	if (sk->atop > 1)
		if (sk->a[sk->atop] < sk->a[sk->atop - 1])
			swapa(sk);
}

void	top_swapb(t_stacks *sk)
{
	if (sk->btop > 1)
		if (sk->b[sk->btop] > sk->b[sk->btop - 1])
			swapb(sk);
}

void	rev_sort(t_stacks *sk)
{
	int	i;

	i = 0;
	while (i++ < sk->lengh && sk->btop > 1)
	{
		top_checkb(sk);
		top_swapa(sk);
	}
}
