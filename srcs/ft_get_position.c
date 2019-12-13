/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:16:52 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/07 21:14:06 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	ft_get_position_from_top(t_stack *stack, int value, int v)
{
	t_stack	*tmp;
	int	index;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->stack == value || (!v && tmp->stack <= value))
			break;
		index++;
		tmp = tmp->next;
	}
	return (index);
}

static int	ft_get_position_from_bot(t_stack *stack, int value, int v)
{
	t_stack	*tmp;
	int	index;

	index = 1;
	tmp = stack;
	while(tmp && tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->stack == value || (!v && tmp->stack <= value))
			break;
		index++;
		tmp = tmp->prev;
	}
	return (index);
}

int	ft_get_position(t_stack *stack, int value, int v)
{
	int	t;
	int	b;

	t = ft_get_position_from_top(stack, value, v);
	b = ft_get_position_from_bot(stack, value, v);
	return (t <= b ? t : -b);
}
