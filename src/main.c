/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/29 13:10:25 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_stack(t_stacks *stack)
{
	int	i;

	i = 9;
	printf("\n");
	while (--i)
		printf("%d->| %d | %d |\n", i, stack->a[i], stack->b[i]);
	printf("---------------------------\n");
	printf(" A	 B		Q%d\n", stack->lengh);
}

void	swapa(t_stacks *sk)
{
	int	*temp;

	temp = sk->a[sk->atop];
	sk->a[sk->atop] = sk->a[sk->atop - 1];
	sk->a[sk->atop - 1] = temp;
}

void	swapb(t_stacks *sk)
{
	int	*temp;

	temp = sk->b[sk->btop];
	sk->b[sk->btop] = sk->b[sk->btop - 1];
	sk->b[sk->btop - 1] = temp;
}

void	pusha(t_stacks *sk)
{
	sk->b[++sk->btop] = sk->a[sk->atop];
}

void	pushb(t_stacks *sk)
{
	sk->b[++sk->btop] = sk->a[sk->atop];
}

void	sort(t_stacks *sk)
{
	// int	i;
	//swaptop(a);
	pusha(sk);
	// i = 1;
	// while (i)
	// {
	// 	if (a->stack[a->top] > )
	// }
}

int	main(int argc, char **argv)
{
	t_stacks stack;
	int		i;

	i = 0;
	stack.lengh = argc - 1;
	while (i++ < 3)
	{
		printf_stack(&stack);
		sort(&stack);
	}
}