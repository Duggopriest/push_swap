/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:25:20 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/11 16:54:02 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stacks *sk)
{
	int	i;

	i = 0;
	while (i < 5 && sk->btop < 1)
	{
		if (sk->a[0] >= 4)
			pushb(sk);
		else
			rotatea(sk);
		i++;
	}
	sort_3(sk);
	pusha(sk);
	pusha(sk);
	if (sk->a[0] == 5)
		swapa(sk);
	rotatea(sk);
	rotatea(sk);
}
