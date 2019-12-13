/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 18:03:04 by kdaou             #+#    #+#             */
/*   Updated: 2019/10/30 18:03:18 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*ft_qsort_part(t_stack *a, t_stack *p)
{
	t_stack	*tmp;
	int		t;
	t_stack	*prev;

	t = p->stack;
	tmp = a;
	prev = a->prev;
	while (tmp != p && tmp)
	{
		if (tmp->stack <= t)
		{
			prev = (prev == NULL) ? a : prev->next;
			ft_swap(&prev->stack, &tmp->stack);
		}
		tmp = tmp->next;
	}
	prev = (prev == NULL) ? a : prev->next;
	ft_swap(&p->stack, &prev->stack);
	return (prev);
}

static void	ft_qsort_r(t_stack *head, t_stack *tail)
{
	t_stack	*p;

	if (head && tail && head != tail && head != tail->next)
	{
		p = ft_qsort_part(head, tail);
		ft_qsort_r(head, p->prev);
		ft_qsort_r(p->next, tail);
	}
}

void	ft_qsort(t_stack *a)
{
	t_stack	*p;

	p = a;
	while (p->next != NULL)
		p = p->next;
	ft_qsort_r(a, p);
}
