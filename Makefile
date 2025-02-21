# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 15:04:48 by palu              #+#    #+#              #
#    Updated: 2025/02/21 11:37:25 by rbouquet         ###   ########.fr        #
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

NAME		=	cub3D
NAME_BONUS		=	cub3D_bonus


RM			= rm -f

FLAGS		=	-Wall -Wextra -Werror -Llib/mlx_linux -lmlx -lX11 -lXext -lm $(LIBFT) $(MLX) -std=c99

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

#MANDATORY
SRC_PATH 	=	mandatory/src/
SRC			=	main.c init_all.c free.c \
				game/init_game.c game/keycode.c game/move.c \
				parsing/error.c parsing/map.c parsing/check_args.c \
				parsing/utils.c parsing/wall_error.c parsing/read_cub.c parsing/read_cub2.c\
				raycasting/raycasting.c raycasting/render.c raycasting/draw.c
SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH	=	mandatory/obj/
OBJ					=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

#BONUS
SRC_PATH_BONUS 	=	bonus/src/
SRC				=	main.c init_all.c free.c \
				game/init_game.c game/keycode.c game/move.c \
				parsing/error.c parsing/map.c parsing/check_args.c \
				parsing/utils.c parsing/wall_error.c parsing/read_cub.c parsing/read_cub2.c\
				raycasting/raycasting.c raycasting/render.c raycasting/draw.c
SRCS_BONUS		=	$(addprefix $(SRC_PATH_BONUS), $(SRC))

OBJ_PATH_BONUS	=	bonus/obj/
OBJ			=	$(SRC:.c=.o)
OBJS_BONUS		=	$(addprefix $(OBJ_PATH_BONUS), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)
bonus: $(MLX) $(LIBFT) $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#MANDATORY
$(NAME): $(OBJS)
	@echo $(CYAN)"Compiling CUB3D..."$(RESET)
	@cc $(OBJS) $(FLAGS) -o $(NAME)
	@echo $(BLUE)"👾Done !👾" $(RESET)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

#BONUS
$(NAME_BONUS): $(OBJS_BONUS)
	@echo $(CYAN)"Compiling CUB3D_BONUS..."$(RESET)
	@cc $(OBJS_BONUS) $(FLAGS) -o $(NAME_BONUS)
	@echo $(BLUE)"👾Done !👾" $(RESET)

$(OBJ_PATH_BONUS)%.o: $(SRC_PATH_BONUS)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		echo $(CYAN)"Cloning 'mlx' from https://github.com/42Paris/minilibx-linux..."; \
		git clone https://github.com/42Paris/minilibx-linux.git lib/mlx_linux $(SILENT); \
		echo $(CYAN)"Compiling MiniLibx..."; \
		make -sC $(MLX_PATH) $(SILENT); \
		echo $(BLUE)"👾Done !👾" $(RESET); \
	elif [ ! -f "$(MLX)" ]; then \
		echo $(CYAN)"Compiling MiniLibx..."; \
		make -sC $(MLX_PATH) $(SILENT); \
		echo $(BLUE)"👾Done !👾" $(RESET); \
	else \
		echo $(YELLOW)"MiniLibx already exists and is compiled, skipping clone and compile." $(RESET); \
	fi

$(LIBFT):
	@echo $(CYAN)"Compiling LIBFT..."$(RESET)
	@make --no-print-directory -C $(LIBFT_PATH)
	@echo $(BLUE)"👾Done !👾" $(RESET)

clean:
	@echo $(RED)"Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(SILENT)
	@if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH) $(SILENT); fi
	@make clean -C $(LIBFT_PATH) $(SILENT)
	@echo $(RED)".o object files removed!"

clean_bonus:
	@echo $(RED)"Removing .o object files..."
	@rm -rf $(OBJ_PATH_BONUS) $(SILENT)
	@if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH) $(SILENT); fi
	@make clean -C $(LIBFT_PATH) $(SILENT)
	@echo $(RED)".o object files removed!"

fclean:	clean clean_bonus
	@echo $(RED)"Removing $(NAME) && $(NAME_BONUS)..."
	@rm -rf $(MLX_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo $(RED)"\n\o\ All created files have been removed! /o/\n"

re: fclean all

.PHONY: all clean fclean re
