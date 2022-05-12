/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:50:53 by marvin            #+#    #+#             */
/*   Updated: 2022/05/06 11:50:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_solved(t_stacks *sk)
{
	int	i;

	i = -1;
	while (++i < sk->lengh - 1 && sk->btop == -1)
		if (sk->a[i] > sk->a[i + 1])
			return (0);
	return (i);
}

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	brd;

	num = 0;
	sign = 1;
	brd = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (brd < 1)
			return (brd);
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}

// void	print_stacks(t_stacks *sk)
// {
// 	int	i;

// 	i = -1;
// 	system("clear");
// 	while (++i < sk->lengh)
// 		printf("%d	->| %d 	| %d 	|\n", i + 1, sk->a[i], sk->b[i]);
// 	printf("----------------------\n");
// 	printf("Q%d A%d   B%d   M%d	bit=%d\n", sk->lengh, sk->atop, sk->btop, sk->total, sk->bit);
// }
