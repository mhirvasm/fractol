# =========================
# Project
# =========================
NAME    = fractol
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -O3 -ffast-math

SRC     = fractol.c init.c math_utils.c render.c events.c ft_atodbl.c ft_strcmp.c
OBJ     = $(SRC:.c=.o)

# =========================
# Libft
# =========================
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# =========================
# MiniLibX (Linux)
# =========================
MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz

# =========================
# Rules
# =========================
.PHONY: all clean fclean re libft mlx clean_mlx

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) -flto $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Objects
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Build libft via its own Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Build MLX so that lib exists
mlx: $(MLX_LIB)
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Clean only our objects (always safe)
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) clean_mlx
	rm -f $(OBJ)

# Clean everything we own; MLX usually doesn’t have fclean, so call clean
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild
re: fclean all
