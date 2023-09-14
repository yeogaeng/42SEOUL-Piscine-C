# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokko <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 18:38:04 by yokko             #+#    #+#              #
#    Updated: 2023/09/14 20:17:39 by yokko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
TARGET = libft.a
SRC = ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, ft_strcmp.c
SRCD = $(addprefix ./srcs/, $(SRC))
OBJS = $(SRCD:.c=.o)
HEAD = ./includes/
CFLAGS = -Wall -Werror -Wextra

all : $(TARGET)

.c.o:
	$(CC) $(CFLAGS) -c -I ${HEAD} $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean:
	clean
	rm -f {TARGET}

re:
	fclean all

$(TARGET) : ${OBJS}
	ar rc $(TARGET) $(OBJS)
