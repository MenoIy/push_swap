/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minilibx.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:13:17 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/06 22:31:30 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include <mlx.h>
# include <stdlib.h>
# include "mathlibft.h"
# include "pthread.h"
# include "libft.h"

typedef enum		e_event_code
{
	MOUSE_PRESS_CODE = 4,
	MOUSE_MOVE_CODE = 6,
	KEY_PRESS_CODE = 2,
	RED_BUTTON_CODE = 17,
}					t_event_code;

typedef enum		e_ft_mlx_hooks
{
	NO_EVENT_HOOK = 0,
	MOUSE_PRESS_HOOK = 1,
	MOUSE_MOVE_HOOK = 2,
	KEY_PRESS_HOOK = 4,
	RED_BUTTON_HOOK = 8,
}					t_ft_mlx_hooks;

typedef enum		e_key_code
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
	ZOOM_IN = 69,
	ZOOM_OUT = 78,
	SPACE = 49,
	NUM_LOCK_9 = 92,
	NUM_LOCK_8 = 91,
	NUM_LOCK_7 = 89,
	NUM_LOCK_6 = 88,
	NUM_LOCK_5 = 87,
	NUM_LOCK_4 = 86,
	NUM_LOCK_3 = 85,
	NUM_LOCK_2 = 84,
	NUM_LOCK_1 = 83,
	NUM_LOCK_0 = 82,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
}					t_key_code;

typedef struct	s_setup
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
}				t_setup;

typedef struct	s_thread_data
{
	void		*data;
	int			min;
	int			max;
}				t_thread_data;

typedef	struct	s_shap
{
	double		a;
	double		b;
	double		m;
	double		n1;
	double		n2;
	double		n3;
	double		phi;
}				t_shap;

t_setup			*ft_new_setup(int width, int height, char *title);
void			ft_mlx_clear_img(t_setup *setup, int x, int y);
int				ft_draw_img(t_setup *setup, int x, int y, t_color color);
double			ft_supershap_3d(t_shap value, double angle);
t_vector		ft_supershap_2d(t_shap value, double angle);

int				ft_thread_gestion(void *data, void *(*f)(void*)
				, int thread_number, int size);

#endif
