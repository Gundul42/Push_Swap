# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/14 05:43:03 by graja             #+#    #+#              #
#    Updated: 2021/09/02 18:52:01 by graja            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BNAME		= checker
LIBFT		= libft
SRC		= pushswap.c 
SRCS		= ft_helpers.c ft_push.c ft_rotate.c ft_sort.c ft_swap.c \
		  ft_fastsort.c ft_values.c ft_array.c \
		  ft_fasthelp.c ft_memory.c ft_lists.c ft_minisort.c \
		  ft_atol.c
BSRCS		= get_next_line.c get_next_line_utils.c checker.c \
		  checker_helper.c
CC		= gcc
FLAGS		= -Wall -Wextra -Werror
RM		= rm -f

$(NAME)	:	$(SRCS) $(LIBFT)
	make bonus -C $(LIBFT)
	$(CC) $(FLAGS) $(SRC) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

all	: $(NAME)


fclean	: clean
	$(RM) $(NAME) $(BNAME)
	make fclean -C $(LIBFT)

clean	: 
	make clean -C $(LIBFT)

re	: fclean all

bonus	: $(NAME) $(SRCS) $(BSRCS) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(BSRCS) -L$(LIBFT) -lft -o $(BNAME)

