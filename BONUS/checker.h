/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:09:11 by jgobbett          #+#    #+#             */
/*   Updated: 2022/05/12 20:22:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_stacks {
	int	*a;
	int	*b;
	int	lengh;
	int	atop;
	int	btop;
	int	total;
	int	bit;
}	t_stacks;

char	*get_next_line(int fd);
void	read_r(char *b, t_stacks *sk);
void	read_s(char *b, t_stacks *sk);
void	read_p(char *b, t_stacks *sk);

void	ss(t_stacks *sk);
void	rr(t_stacks *sk);
void	rrb(t_stacks *sk);
void	pa(t_stacks *sk);
void	ra(t_stacks *sk);
void	rra(t_stacks *sk);
void	sa(t_stacks *sk);
void	pb(t_stacks *sk);
void	rb(t_stacks *sk);
void	rrr(t_stacks *sk);
void	sb(t_stacks *sk);

int		is_solved(t_stacks *sk);
void	free_stacks(t_stacks *sk);

void	putstr(char *str);
void	print_stacks(t_stacks *sk);
int		ft_atoi(const char *str);

#endif