# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vomelchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/06 18:03:35 by vomelchu          #+#    #+#              #
#    Updated: 2018/05/06 18:04:51 by vomelchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= ./main.c  \
		  ./openvalid.c  \
		  ./other.c   \
		  ./ft_strsplit.c \
		  ./cuting.c \
		  ./addfunc.c \
		  ./ft_strjoin.c \
		  ./ft_strsub.c \
		  ./pastlist.c \
		  ./ft_putchar.c \
		  ./ft_putstr.c \
		  ./collisions.c \
		  ./map.c \
		  ./solver.c \
		  ./ft_memset.c \
		  ./ft_putendl.c \
		  ./ft_strnew.c \


OBJ		= $(SRC:.c=.o)

HEADERS = ./

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -I$(HEADERS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
