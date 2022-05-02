/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 07:56:54 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_halveda(t_stacks *sk, int half)
{
	int	i;

	i = sk->atop + 1;
	while (--i)
		if (sk->a[i] < half)
			return (0);
	return (1);
}

int	is_halvedb(t_stacks *sk)
{
	int	i;
	int	j;

	i = sk->btop + 1;
	j = sk->lengh / 2;
	while (--i)
		if (sk->b[i] < j)
			return (1);
	return (0);
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

void	halfa(t_stacks *sk)
{
	int	i;
	int	j;

	i = find_halfa(sk);
	j = 1;
	while(j++ < sk->atop)
	{
		if (sk->a[sk->atop] <= i)
			pusha(sk);
		else
			rotatea(sk);
		printf("j = %d	i = %d\n", j, i);
	}
	sk->blocks = apend_blocks(sk, j);
}

void	sort(t_stacks *sk)
{
	while (sk->atop > 2)
	{
		halfa(sk);
		printf("atop = %d\n", sk->atop);
	}
}
