# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agraille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/26 14:30:23 by agraille          #+#    #+#              #
#    Updated: 2025/03/27 11:52:30 by agraille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all re fclean clean

NAME = harl
CC=c++
CFLAGS=-Wall -Wextra -Werror -std=c++98
SRC = main.cpp Harl.cpp
OBJ_DIR = obj
OBJ	= $(addprefix $(OBJ_DIR)/,$(SRC:%.cpp=%.o))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║   Compilation Success! ✅ ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

$(OBJ_DIR)/%.o: %.cpp Makefile Harl.hpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	@rm -rf $(OBJ) $(OBJ_DIR)/
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Clean OK! 🧽       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

fclean :
	@rm -rf $(NAME) $(OBJ) $(OBJ_DIR)
	@echo "$(GREEN)╔═══════════════════════════╗$(RESET)"
	@echo "$(GREEN)║        Fclean OK! 🪣       ║$(RESET)"
	@echo "$(GREEN)╚═══════════════════════════╝$(RESET)"

re : fclean all
