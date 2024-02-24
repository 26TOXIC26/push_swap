# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 21:51:32 by amousaid          #+#    #+#              #
#    Updated: 2024/02/24 21:51:33 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthex.c\
      ft_putunbr.c
		
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rc $(NAME) $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

.SILENT:
