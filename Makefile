# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:04:57 by framos-p          #+#    #+#              #
#    Updated: 2023/03/02 17:02:06 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	philo

INC				=	inc
SRCS			=	srcs/

SRCS_FILES		=	$(SRCS)main.c $(SRCS)errors.c $(SRCS)utils.c $(SRCS)inits.c $(SRCS)threads.c \
					$(SRCS)mutex_control.c $(SRCS)clean_and_destroy.c $(SRCS)actions.c $(SRCS)print_actions.c

CC				=	gcc
FLAGS			=	-g -Wall -Wextra -Werror -MMD
RM				=	rm -rf

OBJS			=	$(SRCS_FILES:%.c=%.o)

DEPS			=	$(SRCS_FILES:%.c=%.d)

# Colors

NOCOLOR			=	\033[0m
BOLD_PURPLE		=	\033[1;35m
BOLD_CYAN		=	\033[1;36m
RED				=	\033[0;91m
YELLOW			=	\033[5;93m
BLUE			=	\033[0;94m
GREEN			=	\033[0;32m

all:
				@$(MAKE) $(NAME)

%.o: %.c
				@echo "$(BOLD_CYAN)compiling: [$(RED)$<$(BOLD_PURPLE)]"
				@$(CC) $(FLAGS) -I $(INC) -c $< -o $@

$(NAME)::		$(OBJS)
				@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(NAME)::
				@echo "\n$(RED)Pilosophers Compiled ✅$(DEF_COLOR)\n"

clean:
				@$(RM) $(OBJS) $(NAME)
				@$(RM) $(DEPS)
				@echo "\n✅$(YELLOW)Clean: $(RED)Removed Philo's files \n$(DEF_COLOR)"

fclean: clean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
