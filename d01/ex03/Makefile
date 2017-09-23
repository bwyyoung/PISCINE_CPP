# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombie
SRC		=	main.cpp \
			Zombie.cpp \
			ZombieHorde.cpp

OBJ		=	$(SRC:.cpp=.o) #interesting compilation method

FLAGS	=	-Wall -Wextra -Werror
CC		=	clang++
RM		=	rm -rf
INC		=	-I .

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CC) -o $@ -c $< $(FLAGS)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
