/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 16:08:09 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norminize(t_stacks *sk)
{
	int	min;
	int	i;
	int	j;

	min = find_min(sk->a);
	i = 0;
	j = 0;
	while (j < sk->lengh)
	{
		if (min == sk->a[i])
		{
			sk->a[i] = j++;
			min = find_next_min(sk, min);
			i = -1;
		}
		i++;
	}
}

void	int_stacks(t_stacks *sk)
{
	int	*a;
	int	*b;
	int	*c;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	i = 0;
	while (i <= sk->lengh)
	{
		a[i] = i;
		b[i++] = 0;
	}
	norminize(sk);
	sk->a = a;
	sk->b = b;
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc != 3)
		return (0);
	stack.lengh = ft_atoi(argv[1]);
	stack.atop = stack.lengh;
	stack.btop = 0;
	int_stacks(&stack);
	printf_stack(&stack);
	if (argv[1][0] == '3')
		sort_3(&stack);
	else if (argv[1][0] == '5' && !argv[1][1])
		sort_5(&stack);
	else
		sort_bit(&stack);
	printf_stack(&stack);
}
