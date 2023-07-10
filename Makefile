# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edfirmin <edfirmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/20 09:33:55 by edfirmin          #+#    #+#              #
#    Updated: 2023/07/10 12:00:41 by edfirmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c utile1.c checker.c exec.c

FLG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o :
	gcc $(FLG) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJ)
	cd lib ; make
	gcc $(FLG) $(OBJ) lib/libft.a -o $(NAME)

clean :
	cd lib ; make clean
	rm -f $(OBJ)

fclean : clean
	cd lib ; make fclean
	rm -f $(NAME)

re : fclean all