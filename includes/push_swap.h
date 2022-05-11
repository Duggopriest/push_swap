/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:01:31 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/11 16:51:04 by jgobbett         ###   ########.fr       */
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
	int	*c;
	int	lengh;
	int	atop;
	int	btop;
	int	total;
	int	bit;
}	t_stacks;

void	sort_3(t_stacks *sk);
void	sort_5(t_stacks *sk);
void	top_checka(t_stacks *sk);

void	pusha(t_stacks *sk);
void	pushb(t_stacks *sk);
void	rotatea(t_stacks *sk);
void	swapa(t_stacks *sk);
void	swapb(t_stacks *sk);
void	revrotatea(t_stacks *sk);

void	radix(t_stacks *sk);
int		is_solved(t_stacks *sk);
int		checkoverflow(char *str);
void	free_stacks(t_stacks *sk);
void	array_no_rep(t_stacks *sk);
int		array_checker(int argc, char **argv);

int		find_min(t_stacks *sk);
int		find_next_min(t_stacks *sk, int last);

void	putstr(char *str);
void	print_stacks(t_stacks *sk);
int		ft_atoi(const char *str);

#endif