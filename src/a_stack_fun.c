/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 04:48:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 16:18:36 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
	sk->total++;
	putstr("sa\n");
}

void	pusha(t_stacks *sk)
{
	sk->btop++;
	sk->b[sk->btop] = sk->a[sk->atop];
	sk->a[sk->atop--] = 0;
	sk->total++;
	putstr("pa\n");
}

void	rotatea(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->atop + 1;
	temp = sk->a[sk->atop];
	while (--i)
		sk->a[i] = sk->a[i - 1];
	sk->a[1] = temp;
	sk->total++;
	putstr("ra\n");
}