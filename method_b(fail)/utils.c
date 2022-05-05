/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 06:03:32 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 13:50:53 by jgobbett         ###   ########.fr       */
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
	while (++i < sk->lengh && sk->atop == sk->lengh)
		if (sk->a[i] > sk->a[i + 1])
			return (0);
	return (i);
}

int	find_halfb(t_stacks *sk, int k)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	while (i < sk->block_count)
		printf("sk->blocks = %d\n", sk->blocks[i++]);
	i = sk->btop;
	max = 0;
	printf("i = %d\n", i);
	printf("sk->btop - sk->blocks[k] = %d\n", sk->btop - sk->blocks[k]);
	while(--i >= sk->btop - sk->blocks[k])
	{
		printf("%d\n", sk->a[i]);
		if (sk->a[i] > max)
			max = sk->b[i];
	}
	i = sk->btop;
	min = max;
	while(--i >= sk->btop - sk->blocks[k])
		if (sk->a[i] < min)
			min = sk->b[i];
	printf("min = %d	max = %d\n", min, max);
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
