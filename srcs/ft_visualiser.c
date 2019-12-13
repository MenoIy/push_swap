/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visualiser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:16:45 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/09 15:35:21 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


typedef struct	s_elem
{
	t_color	color;
	int	i;
	int	w;
	int	h;
}				t_elem;



static void	ft_split_screen(t_setup	*setup)
{
	int	x;
	int	y;

	y = setup->height / 2;
	x = 0;
	while (x < setup->width)
	{
		x++;
		ft_draw_img(setup, x, y, ft_color_create(255, 255, 255, 0));
	}
}


t_elem	ft_get_element(int a, t_stack *sorted, size_t len)
{
	t_stack	*tmp;
	int	i;
	t_elem	elem;

	i = 1;
	elem.i = 0;
	tmp = sorted;
	while (tmp)
	{
		if (tmp->stack == a)
		{
			elem.i = i;
			elem.color = ft_color_gradient(i, ft_color_create(255, 255, 0, 0),
					ft_color_create(255, 0, 0, 0), len);
			break;
		}
		i++;
		tmp = tmp->next;
	}
	return (elem);
}

void	ft_draw_element(t_setup *setup, t_elem elem, int j, int i)
{
	int x;
	int	y;

	x = i * elem.w;
	while (x < (i + 1) * elem.w)
	{
		y = j;
		while (y > j - elem.h)
		{
			y--;
			ft_draw_img(setup, x, y, elem.color);
		}
		x++;
	}
}

void	ft_draw_stack(t_stack *s, t_data *data, int y)
{
	size_t	len;
	t_stack	*tmp;
	int		i;
	t_elem	elem;

	tmp = s;
	i = 0;
	len = data->stack_size;
	while (tmp)
	{
		elem = ft_get_element(tmp->stack, data->sorted, len);
		elem.w = ((data->setup->width) / len)  ;
		elem.h = ((data->setup->height / 2) / len) * elem.i;
		ft_draw_element(data->setup, elem, y, i);
		i++;
		tmp = tmp->next;
	}
}


void	ft_visualiser(t_data *data)
{
	ft_mlx_clear_img(data->setup, data->setup->width, data->setup->height);
	ft_split_screen(data->setup);
	ft_draw_stack(data->a, data, data->setup->height / 2);
	ft_draw_stack(data->b, data, data->setup->height);
	mlx_put_image_to_window(data->setup->mlx_ptr, data->setup->win_ptr, data->setup->img_ptr, 0, 0);
	mlx_do_sync(data->setup->mlx_ptr);
}
