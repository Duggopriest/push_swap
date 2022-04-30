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

int	is_halveda(t_stacks *sk)
{
	int	i;
	int	j;

	i = sk->atop + 1;
	j = sk->lengh / 2;
	while (--i)
		if (sk->a[i] < j)
			return (0);
	return (1);
}

int	is_halvedb(t_stacks *sk)
{
	int	i;
	int	j;

	i = sk->btop + 1;
	j = sk->lengh / 2;
	while (--i)
		if (sk->b[i] < j)
			return (1);
	return (0);
}
