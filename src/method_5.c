/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:25:20 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/06 15:25:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stacks *sk)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (sk->a[sk->atop] >= 4)
			pushb(sk);
		else
			rotatea(sk);
		i++;
	}
	sort_3(sk);
	pusha(sk);
	pusha(sk);
	if (sk->a[sk->atop] == 4)
		swapa(sk);
}