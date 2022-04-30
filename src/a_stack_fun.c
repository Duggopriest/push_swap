/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_stack_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 04:48:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 06:39:27 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
	printf_stack(sk);
	putstr("SA\n");
}

void	pusha(t_stacks *sk)
{
	sk->btop++;
	sk->b[sk->btop] = sk->a[sk->atop];
	sk->a[sk->atop--] = 0;
	printf_stack(sk);
	putstr("PA\n");
}
