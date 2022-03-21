#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <gnl/get_next_line.h>
# include <libft/libft.h>

typedef struct	s_zone
{
	int		image_y;
	int		image_x;
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	char	**matrice;
}				t_zone;

#endif