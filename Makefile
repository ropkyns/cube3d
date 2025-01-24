# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:04:48 by palu              #+#    #+#              #
#    Updated: 2025/01/24 09:23:07 by paulmart         ###   ########.fr        #
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
SILENT		=	> /dev/null 2>&1

NAME		=	cube3D

RM			= rm -f

FLAGS		=	-Wall -Wextra -Werror -lXext -lX11 -lm $(LIBFT) $(MLX) -std=c99

INC			=	-I ./src/libft/\
				-I ./inc/


#LIBFT
LIBFT_PATH		=	lib/libft/
LIBFT_NAME		=	libft.a
LIBFT			=	$(addprefix $(LIBFT_PATH), $(LIBFT_NAME))

#MLX
MLX_PATH	=	lib/mlx_linux/
MLX_NAME	=	libmlx.a
MLX			=	$(addprefix $(MLX_PATH), $(MLX_NAME))


#SRC
SRC_PATH 	=	src/
SRC			=	main.c init_all.c free.c \
				game/init_game.c game/keycode.c \
				parsing/error.c parsing/map.c parsing/check_args.c \
				parsing/utils.c parsing/wall_error.c parsing/read_cub.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

#OBJ
OBJ_PATH	=	obj/
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo $(RED)"C"$(YELLOW)"o"$(GREEN)"m"$(CYAN)"p"$(BLUE)"i"$(MAGENTA)"l"$(RED)"i"$(YELLOW)"n"$(GREEN)"g" $(CYAN)"c"$(BLUE)"u"$(MAGENTA)"b"$(RED)"e"$(YELLOW)"3"$(GREEN)"d"$(RESET)
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
	@make --no-print-directory -C $(LIBFT_PATH)
	@echo $(RED)"D"$(YELLOW)"o"$(GREEN)"n"$(CYAN)"e"$(BLUE)"!"$(MAGENTA)"!"$(RED)"✨" $(RESET)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo $(RED)"Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(SILENT)
	@if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH) $(SILENT); fi
	@make clean -C $(LIBFT_PATH) $(SILENT)
	@echo $(RED)".o object files removed!"

fclean:	clean
	@echo $(RED)"Removing $(NAME)..."
	@rm -rf $(MLX_PATH)
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo $(RED)"\n\o\ All created files have been removed! /o/\n"

re: fclean all

.PHONY: all clean fclean re
