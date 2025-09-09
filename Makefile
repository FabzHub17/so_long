# Name of the executable
NAME		= so_long

# Compilation flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Iminilibx -g

# Remove files
RM			= rm -f

# Path variables
SRC_PATH	= ./src/
OBJ_PATH	= ./obj/


# Sources
SRC_FILES	= main.c \
			  map/map.c map/map_validate.c map/map_validate_path.c \
			  game/game.c game/game_input.c game/game_exit.c \
			  render/render.c \
			  utils/utils.c  utils/utils2.c utils/ft_itoa.c \
			  utils/ft_printf.c utils/ft_printf_utils.c utils/ft_print_u.c \
			  utils/ft_print_p.c utils/ft_print_int.c utils/ft_print_hex.c \
			  utils/get_next_line.c utils/get_next_line_utils.c

SRCS		= $(addprefix $(SRC_PATH)/, $(SRC_FILES))

# Objects 
OBJS 		= $(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

# MLX
MLX_PATH 	= ./minilibx
MLX			= $(MLX_PATH)/libmlx.a
MLX_FLAGS   = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm


# Rules
all: $(NAME)

$(NAME): $(MLX) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) \
		$(OBJ_PATH)/map \
		$(OBJ_PATH)/game \
		$(OBJ_PATH)/render \
		$(OBJ_PATH)/utils \
		

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
