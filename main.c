/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:06:04 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/28 04:19:11 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*char_int(int argc, char **argv)
{
	int	*a;
	int	i;

	a = malloc(argc);
	i = 0;
	while (i < argc)
		a[i] = ft_atoi(argv[i]);
	return (a);
}

int	main(int argc, char **argv)
{
	t_int	a;
	t_int	b;

	a.a = char_int(argc, argv);
}