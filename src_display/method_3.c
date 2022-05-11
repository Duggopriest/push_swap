/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:35:28 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/11 12:41:49 by jgobbett         ###   ########.fr       */
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
		rotatea(sk);
	else if (sk->a[0] == 2 && sk->a[2] == 3)
		swapa(sk);
	else if (sk->a[0] == 2 && sk->a[2] == 1)
		revrotatea(sk);
	else if (sk->a[0] == 1 && sk->a[2] == 2)
	{
		swapa(sk);
		rotatea(sk);
	}
}
