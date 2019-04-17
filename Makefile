MLX= -L/usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

SRC=fdf_*.c ./gnl/get_next_line.c ./libft/libft.a

all:
	gcc -g $(SRC) $(MLX)

