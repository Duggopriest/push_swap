/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_AB.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:32:41 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 16:42:29 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss(t_stacks *sk)
{
	int	temp;

	temp = sk->b[0];
	sk->b[0] = sk->b[1];
	sk->b[1] = temp;
	temp = sk->a[0];
	sk->a[0] = sk->a[1];
	sk->a[1] = temp;
	sk->total++;
}

void	rr(t_stacks *sk)
{
	int	i;
	int	temp;

	temp = sk->a[0];
	i = -1;
	while (++i < sk->atop)
		sk->a[i] = sk->a[i + 1];
	sk->a[sk->atop] = temp;
	temp = sk->b[0];
	i = -1;
	while (++i < sk->btop)
		sk->b[i] = sk->b[i + 1];
	sk->b[sk->btop] = temp;
	sk->total++;
}

void	rrr(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->btop;
	temp = sk->b[sk->btop];
	while (--i >= 0)
		sk->b[i + 1] = sk->b[i];
	sk->b[0] = temp;
	i = sk->atop;
	temp = sk->a[sk->atop];
	while (--i >= 0)
		sk->a[i + 1] = sk->a[i];
	sk->a[0] = temp;
	sk->total++;
}
