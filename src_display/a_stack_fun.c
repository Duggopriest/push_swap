/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 04:48:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/06 11:38:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_display.h"

void	swapa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
	sk->total++;
	// putstr("SA\n");
	printf_stack(sk);
}

void	pusha(t_stacks *sk)
{
	sk->btop++;
	sk->b[sk->btop] = sk->a[sk->atop];
	sk->a[sk->atop--] = 0;
	sk->total++;
	// putstr("PA\n");
	printf_stack(sk);
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
	printf_stack(sk);
}