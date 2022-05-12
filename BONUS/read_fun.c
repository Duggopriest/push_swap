/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:37:12 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 16:54:35 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_r(char *b, t_stacks *sk)
{
	if (b[1] == 'r')
		rr(sk);
	else if (b[1] == 'a')
		ra(sk);
	else if (b[1] == 'b')
		rb(sk);
	else if (b[1] == 'r')
	{
		if (b[2] == 'a')
			rra(sk);
		else if (b[2] == 'b')
			rb(sk);
		else if (b[2] == 'r')
			rrr(sk);
	}
}

void	read_s(char *b, t_stacks *sk)
{
	if (b[1] == 'a')
		sa(sk);
	if (b[1] == 'b')
		sb(sk);
	if (b[1] == 's')
		ss(sk);
}

void	read_p(char *b, t_stacks *sk)
{
	if (b[1] == 'a')
		pa(sk);
	if (b[1] == 'b')
		pb(sk);
}