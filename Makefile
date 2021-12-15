# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 09:50:13 by maraurel          #+#    #+#              #
#    Updated: 2021/12/15 12:17:43 by maraurel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container

SRC_PATH = ./src/src_ft
SRC_PATH_STD = ./src/src_std

FT_OBJ_PATH = ./obj_ft
STD_OBJ_PATH = ./obj_std

SRC = $(notdir $(wildcard ./src/src_ft/*.cpp))
SRC_STD = $(notdir $(wildcard ./src/src_std/*.cpp))

OBJ = $(addprefix $(FT_OBJ_PATH)/, $(SRC:.cpp=.o))
OBJ_STD = $(addprefix $(STD_OBJ_PATH)/, $(SRC_STD:.cpp=.o))

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME) $(OBJ) $(OBJ_STD)

$(NAME): $(OBJ) $(OBJ_STD)
	@echo "Compiling FT tests..."
	@$(CC) $(FLAGS) $(OBJ) -o ft_tests.out
	@echo "Compiling STD tests..."
	@$(CC) $(FLAGS) $(OBJ_STD) -o std_tests.out

$(FT_OBJ_PATH)/%.o:	$(SRC_PATH)/%.cpp
	@$(CC) -g $(FLAGS) -c $< -o $@

$(STD_OBJ_PATH)/%.o:	$(SRC_PATH_STD)/%.cpp
	@$(CC) -g $(FLAGS) -c $< -o $@

fclean: clean
	@$(RM) ft_tests.out
	@echo "ft_tests.out removed"
	@$(RM) std_tests.out
	@echo "std_tests.out removed"

clean:
	@echo "Cleaning obj_ft folder..."
	@$(RM) $(FT_OBJ_PATH)/*.o
	@echo "Cleaning obj_std folder..."
	@$(RM) $(STD_OBJ_PATH)/*.o

re: fclean all

git:
	git add .
	git commit -m "update"
	git push

run: re
	@./ft_tests.out

memory: re
	@valgrind ./a.out