NAME	=	cub3D

framework =	-lmlx -framework OpenGL -framework AppKit

CFILES =	srcs/color.c srcs/cub3d.c srcs/dda_help.c srcs/dda.c srcs/deal_key.c\
			srcs/draw_other.c srcs/map_int.c srcs/mlx.c srcs/pars_map.c\
			srcs/pars.c srcs/pos_map.c srcs/rendering.c srcs/utils_pars.c\
			srcs/utils_pars2.c gnl/get_next_line_utils.c gnl/get_next_line.c\
			srcs/deal_key_help.c srcs/cub_init.c

OBJECTS = $(CFILES:.c=.o)


INCLUDEL = cub3d.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDEL)
	make bonus -C libft
	make -C libft
	$(CC) $(CFLAGS) $(framework) $(CFILES) libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJECTS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make clean -C libft

re: fclean all

call: all clean