/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_fun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 04:47:59 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 06:37:21 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swapb(t_stacks *sk)
{
	int	temp;

	temp = sk->b[sk->btop];
	sk->b[sk->btop] = sk->b[sk->btop - 1];
	sk->b[sk->btop - 1] = temp;
	sk->total++;
	// putstr("SB\n");
	printf_stack(sk);
}

void	pushb(t_stacks *sk)
{
	sk->a[++sk->atop] = sk->b[sk->btop];
	sk->b[sk->btop--] = 0;
	sk->total++;
	// putstr("PB\n");
	printf_stack(sk);
}