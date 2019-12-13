/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 10:03:45 by kdaou             #+#    #+#             */
/*   Updated: 2019/10/31 09:40:58 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		ret;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (1);
	if (!(ft_verify_args(argv, &a)))
	{
		ft_putendl_fd("ERROR", 2);
		ft_stackdel(&a);
		return (1);
	}
	if ((ret = ft_do_instruction(&a, &b)) == 1)
		ft_putendl("OK");
	else if (ret == 0)
		ft_putendl("KO");
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}
