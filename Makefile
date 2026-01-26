# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2026/01/24 21:35:30 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	libft/*.c \
	ft_op_init.c \
	ft_op_add.c \
	ft_op_count.c \
	ft_op_del_lst.c \
	ft_op_disp.c \
	ft_op_disp_lst.c \
	ft_stack_init.c \
	ft_stack_del.c \
	ft_stack_norme.c \
	ft_stack_add_element.c \
	ft_stack_push.c \
	ft_stack_reverse_rotate.c \
	ft_stack_rotate.c \
	ft_stack_swap.c \
	ft_stack_check.c \
	ft_stack_disorder.c \
	ft_stack_min.c \
	ft_stack_max.c \
	ft_stack_pos_min.c \
	ft_stack_pos_max.c \
	ft_stack_swap_pos.c \
	ft_sort_insertion.c \
	ft_sort_insertion_invert.c \
	ft_sort_selection.c \
	ft_sort_bubble.c \
	ft_sort_min_max.c \
	ft_sort_chunk.c \
	ft_sort_bucket.c \
	ft_sort_radix.c \
	ft_push_swap_benchmark.c \
	ft_push_swap_parser.c \
	ft_push_swap_error.c \
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
	./$(TEST_PROG) 12 34 56 78 96 999 456 123 321 654 987 2 42 0 45 24
