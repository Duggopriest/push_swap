/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:25:20 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/06 11:38:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_display.h"

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
	pushb(sk);
	pushb(sk);
	pushb(sk);
}

void	sort_5(t_stacks *sk)
{
	printf("working\n");
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (sk->a[i] >= 3)
			pusha(sk);
		else
			rotatea(sk);
	}
	if (sk->a[2] > sk->a[1])
		swapa(sk);
	sortb_3(sk);
}