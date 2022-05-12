/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_A.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:15:07 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 16:33:23 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stacks *sk)
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
	sk->total++;
}

void	ra(t_stacks *sk)
{
	int	i;
	int	temp;

	temp = sk->a[0];
	i = -1;
	while (++i < sk->atop)
		sk->a[i] = sk->a[i + 1];
	sk->a[sk->atop] = temp;
	sk->total++;
}

void	rra(t_stacks *sk)
{
	int	i;
	int	temp;

	i = sk->atop;
	temp = sk->a[sk->atop];
	while (--i >= 0)
		sk->a[i + 1] = sk->a[i];
	sk->a[0] = temp;
	sk->total++;
}

void	sa(t_stacks *sk)
{
	int	temp;

	temp = sk->a[0];
	sk->a[0] = sk->a[1];
	sk->a[1] = temp;
	sk->total++;
}
