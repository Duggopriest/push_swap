/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:03:32 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 06:32:51 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	is_solved(t_stacks *sk)
{
	int	i;

	i = -1;
	while(++i < sk->lengh && sk->atop == sk->lengh)
		if (sk->a[i] > sk->a[i + 1])
			return(0);
	return (i);
}

int	find_halfa(t_stacks *sk)
{
	int	i;
	int	min;
	int	max;

	i = -1;
	min = 0;
	max = 0;
	while(++i < sk->atop)
	{
		if (sk->a[i] < min)
			min = sk->a[i];
		if (sk->a[i] > max)
			max = sk->a[i];
	}
	if (min < 0)
		return (((min + max) / 2) / 2);
	return ((min + max) / 2);
}