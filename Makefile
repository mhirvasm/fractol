NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3  -ffast-math

# Sources and objects
SRC = fractol.c init.c math_utils.c render.c events.c ft_atodbl.c ft_strcmp.c
OBJ = $(SRC:.c=.o)

# Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# MiniLibX (Linux)
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

# Default rule
all: $(LIBFT) $(NAME)

# Build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build fractol
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -flto  $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Compile source files to objects
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Clean object files
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

# Clean all
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Rebuild all
re: fclean all
