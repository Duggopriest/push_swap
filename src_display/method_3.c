/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:35:28 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/06 14:56:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stacks *sk)
{
	if (sk->a[0] == 3 && sk->a[2] == 1)
	{
		rotatea(sk);
		swapa(sk);
	}
	else if (sk->a[0] == 3 && sk->a[2] == 2)
	{
		rotatea(sk);
		rotatea(sk);
	}
	else if (sk->a[2] == 3 && sk->a[0] == 2)
	{
		rotatea(sk);
		rotatea(sk);
		swapa(sk);
	}
	else if (sk->a[2] == 1 && sk->a[0] == 2)
		rotatea(sk);
}