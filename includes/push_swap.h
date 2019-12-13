/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 09:47:27 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/08 19:27:27 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "checker.h"
#include "ft_mlx.h"
#include "mathlibft.h"



typedef	struct	s_data
{
	t_setup	*setup;
	t_stack	*a;
	t_stack	*b;
	t_stack	*sorted;
	size_t	stack_size;
}				t_data;

typedef struct	s_limit
{
	int	big;
	int	small;
	int	middle;
}				t_limit;

void	ft_find_instruction(t_data *data);
void	ft_visualiser(t_data *data);
int		ft_get_position(t_stack *stack, int value, int v);



#endif
