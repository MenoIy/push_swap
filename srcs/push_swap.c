/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:00:45 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/08 19:54:50 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	ft_ini_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->sorted = NULL;
	data->stack_size = 0;
	data->setup = NULL;
}

static int	ft_del_data(t_data *data)
{
	ft_stackdel(&(data->a));
	ft_stackdel(&(data->b));
	ft_stackdel(&(data->sorted));
	if (data->setup)
	{
		mlx_destroy_image(data->setup->mlx_ptr, data->setup->img_ptr);
		mlx_destroy_window(data->setup->mlx_ptr, data->setup->win_ptr);
		ft_memdel((void **)&(data->setup));
		exit(0);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	data;
	int		i;

	ft_ini_data(&data);
	i = 0;
	if (argc < 2)
		return (1);
	i = ft_strcmp(argv[1], "-v") == 0;
	if (!(ft_verify_args(argv + i, &(data.a))))
	{
		ft_del_data(&data);
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	if (i)
		data.setup = ft_new_setup(2000, 1000, "push_swap");
	ft_find_instruction(&data);
	if (data.setup)
	{
		mlx_hook(data.setup->win_ptr, 17, 0, &ft_del_data, &data);
		mlx_loop(data.setup->mlx_ptr);
	}
	ft_del_data(&data);
	return (0);
}
