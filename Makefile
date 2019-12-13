# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdaou <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 17:26:52 by kdaou             #+#    #+#              #
#    Updated: 2019/11/07 14:22:16 by kdaou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker

FLAG = -Wall -Wextra -Werror

PSW =	ft_get_position.c\
		push_swap.c\
		ft_find_instruction.c\
		ft_stack.c\
		ft_stack_operation.c\
		ft_do_instruction.c\
		ft_verify_args.c\
		ft_sort_stack.c\
		ft_visualiser.c

CHK =	ft_stack.c\
		ft_stack_operation.c\
		ft_do_instruction.c\
		ft_verify_args.c\
		ft_sort_stack.c\
		checker.c

LIBFT = libft/libft.a

SRC_PSW = $(addprefix srcs/,$(PSW))
SRC_CHK = $(addprefix srcs/,$(CHK))

OBJ_PSW = $(SRC_PSW:.c=.o)
OBJ_CHK = $(SRC_CHK:.c=.o)
VIS = -I /usr/local/Include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
INC = -I includes/
INC_SRCS = includes/libft.h includes/ft_mlx.h includes/mathlibft.h includes/checker.h includes/push_swap.h

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(OBJ_PSW)
	@make -C libft
	@gcc $(OBJ_PSW) $(LIBFT) $(VIS) -o $(PUSH_SWAP)

$(CHECKER): $(OBJ_CHK)
	@make -C libft
	@gcc $(OBJ_CHK) $(LIBFT) -o $(CHECKER)

$(OBJ_PSW): %.o : %.c $(INC_SRCS)
	@gcc -o $@ -c $< $(FLAG) $(INC)

$(OBJ_CHK): %.o : %.c $(INC_SRCS)
	@gcc -o $@ -c $< $(FLAG) $(INC)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ_PSW)
	@rm -f $(OBJ_CHK)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(PUSH_SWAP)
	@rm -f $(CHECKER)
re: fclean all
