# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2026/01/10 19:10:38 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_atoi.c \
	ft_op_init.c \
	ft_op_add.c \
	ft_op_del.c \
	ft_stack_init.c \
	ft_stack_del.c \
	ft_stack_norme.c \
	ft_stack_add_element.c \
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

TEST_PROG = push_swap_test

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME) $(TARGET)

re : fclean all

clear :
	clear

test : clear $(TEST_PROG)

$(TEST_PROG) : $(SOURCES)
	$(CC) $(SOURCES) -o $(TEST_PROG)
	./$(TEST_PROG) 12 34 56 78 96 999 456 123 321 654 987 2 42
