CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = so_long.c check_map.c check_map2.c error.c ft_functions.c init_functions.c mlx_setting.c mlx_setting2.c GNL/get_next_line_utils.c GNL/get_next_line.c
NAME = so_long
HEADER = so_long.h
MLX = libmlx.a
MLX_DIR = mlx

.PHONY : all clean fclean re

all : $(NAME)

re : fclean all

clean :
	make -C $(MLX_DIR) clean
	rm -rf $(MLX)

fclean : clean 
	rm -rf $(NAME)

$(NAME) : $(SRCS) $(HEADER) $(MLX)
	$(CC) $(CFLAGS) $(SRCS) -L . -l mlx -framework OpenGL -framework AppKit -o $@

$(MLX):
	make -C $(MLX_DIR)
	mv $(MLX_DIR)/$(MLX) $(MLX)