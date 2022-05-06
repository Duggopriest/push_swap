/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:25:20 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/06 12:41:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotateb(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->btop + 1;
	temp = sk->b[sk->btop];
	while (--i)
		sk->b[i] = sk->b[i - 1];
	sk->b[0] = temp;
	sk->total++;
	putstr("rb\n");
}

void	sortb_3(t_stacks *sk)
{
	if (sk->b[2] == 2 && sk->b[3] == 1)
		swapb(sk);
	else if (sk->b[1] == 2 && sk->b[3] == 1)
		rotateb(sk);
	else if (sk->b[3] == 1 && sk->b[1] == 3)
	{
		rotateb(sk);
		swapb(sk);
	}
	pusha(sk);
	pusha(sk);
	pusha(sk);
}

void	sort_5(t_stacks *sk)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (sk->a[i] >= 3)
			pushb(sk);
		else
			rotatea(sk);
	}
	if (sk->a[2] > sk->a[1])
		swapa(sk);
	sortb_3(sk);
}