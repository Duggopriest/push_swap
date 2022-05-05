/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 18:55:06 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_stack(t_stacks *sk)
{
	int			i;

	i = sk->lengh + 1;
	//system("clear");
	while (--i)
		printf("%d->	| %i 	| %i 	|| %i 	|\n", i - 1, sk->a[i - 1], sk->b[i - 1], sk->c[i - 1]);
	printf("-------------------\n");
	printf("    		A%d  B%d	Q%d\n", sk->atop, sk->btop, sk->lengh);
	printf("Count	%d / %d Max\n", sk->total, sk->max);
	//usleep(1000000);
}

void	norminize(t_stacks *sk)
{
	int	min;
	int	i;
	int	j;

	min = find_min(sk);
	i = 0;
	j = 1;
	while (j <= sk->lengh)
	{
		if (min == sk->c[i])
		{
			sk->a[i] = j++;
			min = find_next_min(sk, min);
			i = -1;
		}
		i++;
	}
}

void	int_stacks(t_stacks *sk, char **argv)
{
	int	*a;
	int	*b;
	int	*c;
	int	i;

	a = malloc(sizeof(int) * sk->lengh);
	b = malloc(sizeof(int) * sk->lengh);
	c = malloc(sizeof(int) * sk->lengh);
	i = 0;
	while (i < sk->lengh)
	{
		c[i] = ft_atoi(argv[i + 1]);
		a[i] = 0;
		b[i] = 0;
		i++;
	}
	sk->a = a;
	sk->b = b;
	sk->c = c;
	printf_stack(sk);
	norminize(sk);
	printf_stack(sk);
}

void	top_checka(t_stacks *sk)
{
	if (sk->a[sk->atop] > sk->a[sk->atop - 1])
		swapa(sk);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;

	if (argc < 2)
		return (1);
	array_checker(argc, argv);
	stack.lengh = argc - 1;
	stack.atop = stack.lengh;
	stack.btop = 0;
	int_stacks(&stack, argv);
	if (is_solved(&stack))
		return (0);
	else if (argc == 3)
		swapa(&stack);
	else if (argc == 4)
		sort_3(&stack);
	else if (argc == 6)
		sort_5(&stack);
	else
		sort_bit(&stack);
	printf_stack(&stack);
}
