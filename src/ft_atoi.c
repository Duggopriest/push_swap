/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:49:25 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/29 16:14:21 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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