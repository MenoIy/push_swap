/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 09:59:44 by kdaou             #+#    #+#             */
/*   Updated: 2019/11/01 13:51:00 by kdaou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# include <limits.h>
# include <stdio.h>
# define STATIC_ARRAY_SIZE(ptr) (sizeof(ptr) / sizeof(ptr[0]))
# define A 'a'
# define B 'b'


typedef struct		s_instruction
{
	char			*inst;
	short			arg;
	char			stack1;
	char			stack2;
	void			(*call1)();
	void			(*call2)();
}					t_instruction;

typedef struct	s_stack
{
	int		stack;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int				ft_is_numeric(char *str);
int				ft_stack_is_sorted(t_stack *stack);
int				ft_verify_args(char **argv, t_stack **a);


int				ft_do_instruction(t_stack **a, t_stack **b);
void			ft_print_stack(t_stack *a, t_stack *b);

t_stack			*ft_new_stack(int n);
void			ft_stackadd(t_stack **stack, t_stack *new);
void			ft_stackdel(t_stack **stack);
t_stack			*ft_stack_copy(t_stack *stack);
size_t			ft_stack_len(t_stack *stack);
void			ft_qsort(t_stack *a);

/*stack operation*/
void			ft_swap_stack_up(t_stack **x, char *inst);
void			ft_push_stack(t_stack **from, t_stack **to, char *inst);
void			ft_rotate_stack(t_stack **x, char *inst);
void			ft_reverse_stack(t_stack **x, char *inst);

#endif
