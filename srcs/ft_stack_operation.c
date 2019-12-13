/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:24:12 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/07 19:53:26 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_stack_up(t_stack **x, char *inst)
{
	if (*x && (*x)->next)
		ft_swap(&((*x)->stack), &((*x)->next->stack));
	if (inst)
		ft_putendl(inst);
}

void	ft_push_stack(t_stack **from, t_stack **to, char *inst)
{
	t_stack *tmp;

	if (*from)
	{
		tmp = (*from);
		(*from) = (*from)->next;
		if (*from)
			(*from)->prev = NULL;
		tmp->next = *to;
		if (*to)
			(*to)->prev = tmp;
		*to = tmp;
	}
	if (inst)
		ft_putendl(inst);
}

void	ft_reverse_stack(t_stack **x, char *inst)
{
	t_stack *tmp;
	t_stack	*prev;

	if ((*x) && (*x)->next)
	{
		tmp = (*x);
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->prev =  NULL;
		(*x)->prev = tmp;
		tmp->next = (*x);
		(*x) = tmp;
	}
	if (inst)
		ft_putendl(inst);
}

void	ft_rotate_stack(t_stack **x, char *inst)
{
	t_stack	*head;
	t_stack *tmp2;

	if ((*x) && (*x)->next)
	{
		head = (*x);
		tmp2 = (*x)->next;
		tmp2->prev = NULL;
		(*x) = (*x)->next;
		tmp2 = (*x);
		while (tmp2->next)
			tmp2 = tmp2->next;
		head->next = NULL;
		head->prev = tmp2;
		tmp2->next = head;
	}
	if (inst)
		ft_putendl(inst);
}
