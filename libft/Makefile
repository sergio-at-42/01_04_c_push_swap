# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 17:08:31 by sbeldjao          #+#    #+#              #
#    Updated: 2026/02/01 14:18:26 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES =  \
	ft_strlen.c \
	ft_strcmp.c \
	ft_strlcat.c \
	ft_atoi.c \
	ft_itoa.c\
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c
	 
OBJECTS = $(SOURCES:.c=.o)

TARGET = prog

all : $(NAME) clean

$(NAME) : $(OBJECTS)
	ar r $(NAME) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all
