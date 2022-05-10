/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:36:53 by marvin            #+#    #+#             */
/*   Updated: 2022/05/06 11:36:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_stacks *sk)
{
	int	i;

	i = sk->atop + 2;
	while (--i >= 0)
		sk->a[i] = sk->a[i - 1];
	sk->a[0] = sk->b[0];
	i = -1;
	while (++i <= sk->btop)
		sk->b[i] = sk->b[i + 1];
	sk->b[sk->btop] = 0;
	sk->btop--;
	sk->atop++;
	putstr("pb\n");
}

void	pushb(t_stacks *sk)
{
	int	i;

	i = sk->btop + 2;
	while (--i >= 0)
		sk->b[i] = sk->b[i - 1];
	sk->b[0] = sk->a[0];
	i = -1;
	while (++i <= sk->atop)
		sk->a[i] = sk->a[i + 1];
	sk->a[sk->atop] = 0;
	sk->atop--;
	sk->btop++;
	putstr("pb\n");
}

void	rotatea(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->atop + 1;
	temp = sk->a[sk->atop];
	while (--i)
		sk->a[i] = sk->a[i - 1];
	sk->a[0] = temp;
	sk->total++;
	putstr("ra\n");
}

void	swapa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
	sk->total++;
	putstr("sa\n");
}

void	swapb(t_stacks *sk)
{
	int	temp;

	temp = sk->b[sk->btop];
	sk->b[sk->btop] = sk->b[sk->btop - 1];
	sk->b[sk->btop - 1] = temp;
	sk->total++;
	putstr("sb\n");
}
