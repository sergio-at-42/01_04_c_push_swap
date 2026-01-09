# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2026/01/09 14:14:19 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_atoi.c \
	ft_op_init.c \
	ft_op_add.c \
	ft_stack_init.c \
	ft_stack_add_element.c \
	ft_stack_del_element.c \
	ft_stack_push.c \
	ft_stack_reverse_rotate.c \
	ft_stack_rotate.c \
	ft_stack_swap.c \
	ft_stack_check.c \
	ft_stack_min.c \
	ft_stack_max.c \
	ft_stack_pos_min.c \
	ft_stack_pos_max.c \
	ft_stack_swap_pos.c \
	ft_sort_insertion.c \
	ft_sort_selection.c \
	push_swap.c

OBJECTS = $(SOURCES:.c=.o)

TARGET = prog

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME) $(TARGET)

re : fclean all
