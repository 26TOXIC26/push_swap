# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amousaid <amousaid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 10:31:55 by amousaid          #+#    #+#              #
#    Updated: 2024/02/06 00:29:43 by amousaid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC= ft_atoi.c\
     ft_strlen.c\
	 ft_isdigit.c\
	 ft_split.c\
	 ft_strjoin.c\
	 ft_lstnew_bonus.c\
	 ft_lstlast_bonus.c\
	 ft_lstadd_back_bonus.c\
	 ft_strdup.c\
	 ft_lstdelone_bonus.c\
	 ft_lstclear_bonus.c\
 
OBJ= $(SRC:.c=.o)
CC= cc
CFLAGS= -Wall -Wextra  -Werror 
RM= rm -f
AR= ar -rc

.PHONY: all clean fclean re

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)	

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
