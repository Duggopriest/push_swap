/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:54:06 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 17:19:51 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_stacks(t_stacks *sk)
{
	void	*temp;

	temp = sk->a;
	free(temp);
	temp = sk->b;
	free(temp);
	temp = sk->c;
	free(temp);
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
		a[i] = ft_atoi(argv[i + 1]);
		b[i] = 0;
		i++;
	}
	sk->a = a;
	sk->b = b;
	sk->c = c;
}

void	flag_handler(char *b, t_stacks *sk)
{
	if (b[0] == 'r')
		read_r(b, sk);
	else if (b[0] == 's')
		read_s(b, sk);
	else if (b[0] == 'p')
		read_p(b, sk);
}

void	read_commands(t_stacks *sk)
{
	char	*b;

	while (1)
	{
		b = get_next_line(0);
		if (!b)
			break ;
		flag_handler(b, sk);
		free(b);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	sk;

	sk.lengh = argc - 1;
	sk.total = 0;
	sk.btop = -1;
	sk.atop = sk.lengh - 1;
	if (argc <= 1)
		return (0);
	int_stacks(&sk, argv);
	read_commands(&sk);
	print_stacks(&sk);
	if (is_solved(&sk))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(&sk);
}
