/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:20:30 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/01 11:20:50 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 09:29:43 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/01 11:17:55 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		ft_print_stack(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	tmp = a;
	dprintf(2, "stack = a:\n");
	while (tmp)
	{
		dprintf(2, " `%d` \n", tmp->stack);
		tmp = tmp->next;
	}
	tmp = b;
	dprintf(2, "\nstack = b:\n");
	while (tmp)
	{
		dprintf(2, " `%d` \n", tmp->stack);
		tmp = tmp->next;
	}

	dprintf(2, "\n-----------------------------------------------\n");
}

int		ft_stack_is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->stack >= tmp->next->stack)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_numeric(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

int	ft_check_duplicate(t_stack **a)
{
	t_stack	*cpy;
	int		ret;

	cpy = ft_stack_copy(*a);
	ft_qsort(cpy);
	if (!(ret = ft_stack_is_sorted(cpy)))
		ft_stackdel(a);
	ft_stackdel(&cpy);
	return (ret);
}

int	ft_verify_args(char **argv, t_stack **a)
{
	int		i;
	int		j;
	char	**tab;

	j = 0;
	while (argv[++j])
	{
		i = -1;
		tab = ft_strsplit(argv[j], ' ');
		while (tab[++i])
		{
			if (ft_is_numeric(tab[i]))
				ft_stackadd(a, ft_new_stack(ft_atof(tab[i])));
			else
			{
				ft_stackdel(a);
				return (0);
			}
		}
		ft_free_table(&tab);
	}
	return (ft_check_duplicate(a));
}
