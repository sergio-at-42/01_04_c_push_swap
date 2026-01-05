# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2026/01/05 19:59:22 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
	ft_atoi.c \
	ft_stack_init.c \
	ft_stack_pop.c \
	ft_stack_push.c \
	ft_stack_reverse_rotate.c \
	ft_stack_rotate.c \
	ft_stack_swap.c \
	ft_insertion_sort.c \
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
