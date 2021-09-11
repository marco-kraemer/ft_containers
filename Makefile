# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 09:50:13 by maraurel          #+#    #+#              #
#    Updated: 2021/09/11 14:22:55 by maraurel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC = $(notdir $(wildcard ./src/*.cpp))

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.cpp=.o))

CC = clang++

FLAGS = #-Wall -Wextra -Werror

all: $(NAME) $(OBJ)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.cpp
	@$(CC) -g $(FLAGS) -c $< -o $@

fclean: clean
	@$(RM) $(NAME)

clean:
	@$(RM) $(OBJ_PATH)/*.o

re: fclean all

git:
	git add .
	git commit -m "update"
	git push

run: re
	@./a.out

memory: re
	@valgrind ./a.out