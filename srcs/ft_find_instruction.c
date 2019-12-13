/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 09:45:52 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/10 13:00:20 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest_value(t_stack *stack)
{
	int	n;
	t_stack	*tmp;

	tmp = stack;
	n = tmp->stack;
	while (tmp)
	{
		if (tmp->stack > n)
			n = tmp->stack;
		tmp = tmp->next;
	}
	return (n);
}

int		ft_find_limit(t_stack *a, int limit)
{
	t_stack	*tmp;
	tmp = a;
	while (tmp->next)
	{
		limit--;
		if (limit == 0)
			break;
		tmp = tmp->next;
	}
	return (tmp->stack);
}

int	ft_smallest_value(t_stack *stack)
{
	int	n;
	t_stack	*tmp;

	tmp = stack;
	n = tmp->stack;
	while (tmp)
	{
		if (tmp->stack < n)
			n = tmp->stack;
		tmp = tmp->next;
	}
	return (n);
}

/*void	ft_prepare_stack(t_data *data)
{
	int	big;
	int pos;

	while(data->b)
	{
		big = ft_biggest_value(data->b);
		pos = ft_get_position(data->b, big, 1);
		if (pos == 0)
			break;
		else if (pos == 1 && data->b && data->b->next && data->b->stack < data->b->next->stack)
			ft_swap_stack_up(&(data->b) ,"sb");
		else if (pos < 0)
			ft_reverse_stack(&(data->b), "rrb");
		else if (pos > 0)
			ft_rotate_stack(&(data->b), "rb");
		if (data->setup)
			ft_visualiser(data);
	}
}*/

void	ft_prepare_stack(t_data *data)
{
	int	big;
	int small;

	big = 0;
	small = 0;
	if (!data->b)
	{
		ft_push_stack(&(data->a), &(data->b), "pb");
		return ;
	}
	big = ft_biggest_value(data->b);
	small = ft_smallest_value(data->b);

	if (data->a->stack < data->b->stack && data->a->stack < small)
	{
		ft_push_stack(&(data->a), &(data->b), "pb");
	//	ft_rotate_stack(&(data->b), "rb");
	}
	else
		ft_push_stack(&(data->a), &(data->b), "pb");
}


void	ft_devide_and_push(t_data *data, int size, int limit)
{
	int	n;
	int	pos;
	int	big;
	int pos2;

	n = ft_find_limit(data->sorted, size);
	while (limit && data->a)	
	{
		pos = ft_get_position(data->a, n, 0);
		if (data->b)
		{
			big = ft_biggest_value(data->b);
			pos2 = ft_get_position(data->b, big, 1);
		}
		if (pos == 0)
		{
		//	ft_prepare_stack(data);
			ft_push_stack(&(data->a), &(data->b), "pb");
			limit--;
		}
		/*if (pos == 1)
		{
			if (data->b && pos2 == 1)
			{
				ft_swap_stack_up(&(data->a), NULL);
				ft_swap_stack_up(&(data->b), "ss");
			}
			else
				ft_swap_stack_up(&(data->a), "sa");
		}*/
		else if (pos < 0)
		{
			if (data->b && pos2 < 0)
			{
				ft_reverse_stack(&(data->a), "rrr");
				ft_reverse_stack(&(data->b), NULL);
				}
			else
				ft_reverse_stack(&(data->a), "rra");
		}
		else if (pos > 0)
		{
			if (data->b && pos2 > 0)
			{
				ft_rotate_stack(&(data->a), "rr");
				ft_rotate_stack(&(data->b), NULL);
			}
			else
				ft_rotate_stack(&(data->a), "ra");
		}
		if (data->setup)
			ft_visualiser(data);
	}
}

int	ft_get_last(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->stack);
}


void	ft_push_big(t_data *data)
{
	int	big;
	int	pos;

	while(data->b)
	{
		big = ft_biggest_value(data->b);
		pos = ft_get_position(data->b, big, 1);
		if (pos == 0)
			ft_push_stack(&(data->b), &(data->a), "pa");
		else if (pos == 1 && data->b && data->b->next && data->b->stack < data->b->next->stack)
			ft_swap_stack_up(&(data->b) ,"sb");
		else if (pos < 0)
			ft_reverse_stack(&(data->b), "rrb");
		else if (pos > 0)
			ft_rotate_stack(&(data->b), "rb");
		if (data->setup)
			ft_visualiser(data);
	}
}

void	ft_push_swap(t_data *data)
{
	int	size;
	int	limit;
	int	div;
	size_t	len;

	size = 0;

	while (data->a)
	{
		len = ft_stack_len(data->a);
		div = 0.015 * len + 3.5 ;
		limit = ft_round(ft_stack_len(data->a) / div);
		limit = limit == 0 ? 1 : limit;
		size += limit;
		ft_devide_and_push(data, size, limit);
	}
	ft_push_big(data);
}





void	ft_find_instruction(t_data *data)
{
	data->stack_size = ft_stack_len(data->a);
	data->sorted = ft_stack_copy(data->a);
	ft_qsort(data->sorted);
	ft_push_swap(data);
}
