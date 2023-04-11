# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 11:36:01 by framos-p          #+#    #+#              #
#    Updated: 2023/04/06 17:11:31 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------- VAR DECLARETION --------------------------#
NAME			:=	philo

MANDATORY_DIR	:=	philo/
BONUS_DIR		:=	philo_bonus/

FLAGS			=	-Werror -Wextra -Wall
CC				=	gcc

# ---------------------------------- Colors ---------------------------------- #

DEF_COLOR		=	\033[0;39m
GRAY			=	\033[0;90m
RED				=	\033[0;91m
GREEN			=	\033[0;92m
YELLOW			=	\033[0;93m
BLUE			=	\033[0;94m
MAGENTA			=	\033[0;95m
CYAN			=	\033[0;96m
ORANGE			=	\033[38;5;209m
BROWN			=	\033[38;5;94m
DARK_GRAY		=	\033[38;5;234m
MID_GRAY		=	\033[38;5;245m
DARK_GREEN		=	\033[38;5;64m
DARK_YELLOW		=	\033[38;5;143m

# -------------------------------- ACTIONS ----------------------------------- #

all:
				@$(MAKE) -C $(MANDATORY_DIR)
				@$(MAKE) -C $(BONUS_DIR)

$(NAME): Makefile
				@$(MAKE) -C $(MANDTORY_DIR)

bonus:
				@$(MAKE) -C $(BONUS_DIR)

clean:
				@make clean -sC $(MANDATORY_DIR)
				@make clean -sC $(BONUS_DIR)

fclean: clean
				@echo "$(GREEN)Cleaned and ready for Philosophers!$(DEF_COLOR)"

re: flcean

.PHONY:			all clean fclean re
