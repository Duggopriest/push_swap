/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:01:31 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/05 15:59:36 by jgobbett         ###   ########.fr       */
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
	int	*blocks;
	int	block_count;
	int	total;
	int	max;
}	t_stacks;


void	sort(t_stacks *sk);
void	sort_3(t_stacks *sk);
void	sort_5(t_stacks *sk);
void	sort_bit(t_stacks *sk);

void	norminize(t_stacks *sk);
int		is_solved(t_stacks *sk);
int		ft_atoi(const char *str);
void	putstr(char *str);
void	printf_stack(t_stacks *sk);

int		find_min(t_stacks *sk);
int		find_next_min(t_stacks *sk, int last);

void	pusha(t_stacks *sk);
void	pushb(t_stacks *sk);
void	swapa(t_stacks *sk);
void	swapb(t_stacks *sk);
void	rotatea(t_stacks *sk);
void	rotateb(t_stacks *sk);
void	top_swapa(t_stacks *sk);
void	top_swapb(t_stacks *sk);
void	top_checka(t_stacks *sk);

#endif