# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:04:48 by palu              #+#    #+#              #
#    Updated: 2025/01/17 10:07:44 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET		= "\033[0m"
BLACK		= "\033[30m"
RED			= "\033[31m"
GREEN		= "\033[32m"
YELLOW		= "\033[33m"
BLUE		= "\033[34m"
MAGENTA		= "\033[35m"
CYAN		= "\033[36m"
WHITE		= "\033[37m"

SRC			=	main.c init_all.c \
				parsing/error.c parsing/flood_fill.c parsing/map.c parsing/check_args.c \
				parsing/utils.c parsing/wall_error.c parsing/read_cub.c \

NAME		=	cube3D

FLAGS		=	-Wall -Wextra -Werror lib/libft/libft.a -std=c99

RM			= rm -f

LIB_DIR		=	lib/libft/
LIBFT		=	libft.a

MLX_PATH	=	lib/mlx_linux/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

SILENT		=	> /dev/null 2>&1

SRCS		= $(addprefix ./src/, $(SRC))
OBJS		=	$(SRCS:.c=.o)


all: $(MLX) $(LIB_DIR) $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"m"$(BLUE)"i"$(MAGENTA)"n"$(RED)"i"$(YELLOW)"s"$(GREEN)"h"$(CYAN)"e"$(BLUE)"l"$(MAGENTA)"l"$(RED)"."$(YELLOW)"."$(GREEN)"." $(RESET)
	@cc $(OBJS) $(FLAGS) -o $(NAME)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"💫" $(RESET)

$(MLX):
	@echo $(BLUE)"Making MiniLibx..."
	@echo $(BLUE)"Cloning 'mlx' from https://github.com/42Paris/minilibx-linux..."
	@git clone https://github.com/42Paris/minilibx-linux.git lib/mlx_linux $(SILENT)
	@echo $(BLUE)"Compiling MiniLibx..."
	@make -sC $(MLX_PATH) $(SILENT)

$(LIBFT):
	@echo $(RED)"M"$(YELLOW)"a"$(GREEN)"k"$(CYAN)"i"$(BLUE)"n"$(MAGENTA)"g" $(RED)"l"$(YELLOW)"i"$(GREEN)"b"$(CYAN)"f"$(BLUE)"t"$(MAGENTA)"."$(RED)"."$(YELLOW)"." $(RESET)
	@make --no-print-directory -C $(LIB_DIR)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!" $(RED)"✨" $(RESET)

clean:
	@echo "$(GRAY)Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(SILENT)
	@make clean -C $(MLX_PATH) $(SILENT)
	@make clean -C $(LIBFT_PATH) $(SILENT)
	@echo "$(GRAY).o object files removed!"

fclean:	clean
	@echo "$(GRAY)Removing $(NAME)..."
	@rm -rf $(MLX_PATH)
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(YELLOW)\n\o\ All created files have been removed! /o/\n"

re: fclean all

.PHONY: all clean fclean re
