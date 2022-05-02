/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:03:32 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/02 12:03:22 by jgobbett         ###   ########.fr       */
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

	i = 1;
	max = 0;
	while(++i < sk->atop)
		if (sk->a[i] > max)
			max = sk->a[i];
	i = 1;
	min = max;
	while(++i < sk->atop)
		if (sk->a[i] < min)
			min = sk->a[i];
	printf("min = %d	max = %d	ii = %d\n", min, max, (min + max) / 2);
	if (min < 0)
		return (((min + max) / 2) / 2);
	return ((min + max) / 2);
}

int	*apend_blocks(t_stacks *sk, int new_int)
{
	int	i;
	int	*new;

	i = -1;
	new = malloc(sizeof(int) * sk->block_count + 1);
	while (++i < sk->block_count)
		new[i] = sk->blocks[i];
	sk->block_count++;
	new[i] = new_int;
	free(sk->blocks);
	return (new);
}
