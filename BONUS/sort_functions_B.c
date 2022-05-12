/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_B.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:15:10 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 16:36:06 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_stacks *sk)
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
	sk->total++;
	putstr("pb\n");
}

void	rb(t_stacks *sk)
{
	int	i;
	int	temp;

	temp = sk->b[0];
	i = -1;
	while (++i < sk->btop)
		sk->b[i] = sk->b[i + 1];
	sk->b[sk->btop] = temp;
	sk->total++;
}

void	rrb(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->btop;
	temp = sk->b[sk->btop];
	while (--i >= 0)
		sk->b[i + 1] = sk->b[i];
	sk->b[0] = temp;
	sk->total++;
}

void	sb(t_stacks *sk)
{
	int	temp;

	temp = sk->b[0];
	sk->b[0] = sk->b[1];
	sk->b[1] = temp;
	sk->total++;
}
