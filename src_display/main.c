/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 16:46:31 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shuffle(int *array, size_t n)
{
	if (n > 1)
	{
		size_t i;
		for (i = 1; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
	}
}

void	printf_stack(t_stacks *sk)
{
	int			i;

	i = sk->lengh + 1;
	system("clear");
	while (--i)
		printf("%d->	| %i 	| %i 	|\n", i - 1, sk->a[i], sk->b[i]);
	printf("-------------------\n");
	printf("    		A%d  B%d	Q%d\n", sk->atop, sk->btop, sk->lengh);
	printf("Count	%d / %d Max\n", sk->total, sk->max);
	usleep(1000);
}

void	int_stacks(t_stacks *sk)
{
	int	*a;
	int	*b;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	i = 0;
	while (i <= sk->lengh)
	{
		a[i] = i;
		b[i++] = 0;
	}
	shuffle(a, sk->lengh);
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
	stack.max = ft_atoi(argv[2]);
	int_stacks(&stack);
	printf_stack(&stack);
	printf("ARGC = %d\n", argc);
	if (argv[1][0] == '3')
		sort_3(&stack);
	else if (argv[1][0] == '5' && !argv[1][1])
		sort_5(&stack);
	else
		sort_bit(&stack);
	printf_stack(&stack);
}
