# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 08:52:15 by user42            #+#    #+#              #
#    Updated: 2021/09/08 08:52:16 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC = $(notdir $(wildcard ./src/*.cpp))

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC:.cpp=.o))

CC = clang++

FLAGS = -Wall -Wextra -Werror

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
	git push origin main