/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 13:16:28 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/07 11:48:09 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

const	t_instruction	g_t_op[11] =
{
	{"sa", 1, A, B, &ft_swap_stack_up, NULL},
	{"sb", 1, B, A, &ft_swap_stack_up, NULL},
	{"ss", 1, A, B, &ft_swap_stack_up, &ft_swap_stack_up},
	{"pa", 2, B, A, &ft_push_stack, NULL},
	{"pb", 2, A, B, &ft_push_stack, NULL},
	{"ra", 1, A, B, &ft_rotate_stack, NULL},
	{"rb", 1, B, A, &ft_rotate_stack, NULL},
	{"rr", 1, A, B, &ft_rotate_stack, &ft_rotate_stack},
	{"rra", 1, A, B, &ft_reverse_stack, NULL},
	{"rrb", 1, B, A, &ft_reverse_stack, NULL},
	{"rrr", 1, A, B, &ft_reverse_stack, &ft_reverse_stack}
};

void	ft_call_instruction(const t_instruction inst, t_stack **a, t_stack **b)
{
	if (inst.arg == 1)
	{
		inst.call1(inst.stack1 == A ? a : b, NULL);
		if (inst.call2)
			inst.call2(b, NULL);
	}
	else if (inst.arg == 2)
		inst.call1(inst.stack1 == A ? a : b, inst.stack2 == B ? b : a, NULL);
}

int		ft_do_instruction(t_stack **a, t_stack **b)
{
	char	*line;
	int		i;

	while (get_next_line(0, &line) > 0)
	{
		i = -1;
		while (++i < ((int)STATIC_ARRAY_SIZE(g_t_op)))
			if (ft_strcmp(line , g_t_op[i].inst) == 0)
			{
				ft_call_instruction(g_t_op[i] , a, b);
				break;
			}
		if (i == (int)STATIC_ARRAY_SIZE(g_t_op))
		{
			ft_strdel(&line);
			ft_putendl_fd("ERROR", 2);
			return (-1);
		}
		ft_strdel(&line);
	}
	return (!*b && ft_stack_is_sorted(*a));
}
