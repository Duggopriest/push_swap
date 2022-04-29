/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgobbett <jgobbett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:01:31 by jgobbett          #+#    #+#             */
/*   Updated: 2022/04/29 11:55:22 by jgobbett         ###   ########.fr       */
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
}	t_stacks;

int	ft_atoi(const char *str);

#endif