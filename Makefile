# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: palu <palu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:04:48 by palu              #+#    #+#              #
#    Updated: 2025/01/10 16:18:59 by palu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET			= "\033[0m"
BLACK    		= "\033[30m"
RED      		= "\033[31m"
GREEN    		= "\033[32m"
YELLOW   		= "\033[33m"
BLUE     		= "\033[34m"
MAGENTA  		= "\033[35m"
CYAN     		= "\033[36m"
WHITE    		= "\033[37m"

SRC		=	main.c

NAME	=	cube3d

FLAGS	=	-Wall -Wextra -Werror lib/libft/libft.a -std=c99

RM		= rm -f

LIB_DIR	=	lib/libft/
LIBFT 	=	libft.a

MLX_A = libmlx.a
MLX_DIR = lib/mlx/

SRCS 	= $(addprefix ./src/, $(SRC))
OBJS	=	$(SRCS:.c=.o)


all: $(LIB_DIR) $(LIBFT) $(NAME)

%.o:	%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"m"$(BLUE)"i"$(MAGENTA)"n"$(RED)"i"$(YELLOW)"s"$(GREEN)"h"$(CYAN)"e"$(BLUE)"l"$(MAGENTA)"l"$(RED)"."$(YELLOW)"."$(GREEN)"." $(RESET)
	@cc $(OBJS) $(FLAGS) -o $(NAME)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"💫" $(RESET)

$(MLX): 
	@make --no-print-directory -C $(MLX_DIR)

$(LIBFT):
	@echo $(RED)"M"$(YELLOW)"a"$(GREEN)"k"$(CYAN)"i"$(BLUE)"n"$(MAGENTA)"g" $(RED)"l"$(YELLOW)"i"$(GREEN)"b"$(CYAN)"f"$(BLUE)"t"$(MAGENTA)"."$(RED)"."$(YELLOW)"." $(RESET)
	@make --no-print-directory -C $(LIB_DIR)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"✨" $(RESET)

clean:
	@echo $(RED)"C"$(YELLOW)"l"$(GREEN)"e"$(CYAN)"a"$(BLUE)"n"$(MAGENTA)"i"$(RED)"n"$(YELLOW)"g" $(GREEN)"m"$(CYAN)"i"$(BLUE)"n"$(MAGENTA)"i"$(RED)"s"$(YELLOW)"h"$(GREEN)"e"$(CYAN)"l"$(BLUE)"l"$(MAGENTA)"."$(RED)"."$(YELLOW)"." $(RESET)
	@rm -f $(OBJS)
	@make clean --no-print-directory -C $(LIB_DIR)
	@make clean --no-print-directory -C $(MLX_DIR)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"🧹" $(RESET)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIB_DIR)$(LIBFT)
	@rm -f $(MLX_DIR)$(MLX_A)

re: fclean all

.PHONY: all clean fclean re