# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2025/12/20 21:22:17 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = \
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
