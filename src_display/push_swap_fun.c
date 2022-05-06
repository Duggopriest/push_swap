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
	sk->atop++;
	sk->a[sk->atop] = sk->b[sk->btop];
	sk->b[sk->btop--] = 0;
	sk->total++;
	//putstr("pa\n");
	print_stacks(sk);
}

void	pushb(t_stacks *sk)
{
	sk->btop++;
	sk->b[sk->btop] = sk->a[sk->atop];
	sk->a[sk->atop--] = 0;
	sk->total++;
	//putstr("pb\n");
	print_stacks(sk);
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
	//putstr("ra\n");
	print_stacks(sk);
}

void	swapa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
	sk->total++;
	//putstr("sa\n");
}

void	swapb(t_stacks *sk)
{
	int	temp;

	temp = sk->b[sk->btop];
	sk->b[sk->btop] = sk->b[sk->btop - 1];
	sk->b[sk->btop - 1] = temp;
	sk->total++;
	//putstr("sb\n");
}
