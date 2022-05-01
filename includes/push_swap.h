/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:01:31 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/30 06:35:11 by jgobbett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	lengh;
	int	atop;
	int	btop;
	int	current;
	int	total;
	int	max;
}	t_stacks;


void	sort(t_stacks *sk);

int		ft_atoi(const char *str);
void	pushb(t_stacks *sk);
void	swapb(t_stacks *sk);
void	pusha(t_stacks *sk);
void	swapa(t_stacks *sk);
void	top_checka(t_stacks *sk);
void	top_swapb(t_stacks *sk);
void	putstr(char *str);
void	rev_sort(t_stacks *sk);
void	printf_stack(t_stacks *sk);
int		is_solved(t_stacks *sk);
void	rotatea(t_stacks *sk);
int		is_halveda(t_stacks *sk, int half);
int		is_halvedb(t_stacks *sk);
int		find_halfa(t_stacks *sk);

#endif