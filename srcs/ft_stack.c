/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 11:07:57 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/07 19:28:21 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack		*ft_new_stack(int n)
{
	t_stack	*l;

	if (!(l = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	l->stack = n;
	l->next = NULL;
	l->prev = NULL;
	return (l);
}

void		ft_stackadd(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL)
		*stack = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void		ft_stackdel(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
}

t_stack		*ft_stack_copy(t_stack *stack)
{
	t_stack	*new;
	t_stack	*head;

	new = NULL;
	head = stack;
	while (head)
	{
		ft_stackadd(&new, ft_new_stack(head->stack));
		head = head->next;
	}
	return (new);
}

size_t	ft_stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*tmp;

	tmp = stack;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
