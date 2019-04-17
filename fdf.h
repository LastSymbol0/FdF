/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:35:47 by aillia            #+#    #+#             */
/*   Updated: 2019/04/13 12:57:46 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "stdio.h"


# include "mlx.h"
# include "gnl/get_next_line.h"
# include <math.h>

# define BLUE << 0;
# define GREEN << 8;
# define RED << 16;

# define USAGE \
	"usage:\n\t\t./fdf path_to_file.fdf [step] [window_width] [window_height]\n"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;	
}				t_point;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
}				t_line;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
}				t_mlx;

typedef struct	s_fdf
{
	t_mlx		mlx;

	int			rows;
	int			colums;
	int			**map;
	int			step;
	int			iso;
	int			margin;
	int			color_coef;
}				t_fdf;

/*fdf_color.c*/
int				create_color(int red, int green, int blue);

/*fdf_line.c*/
void			put_line(t_line line, t_fdf fdf);
void			line_Ybigger(t_line line, int deltaX, int deltaY, t_fdf fdf);
void			line_Xbigger(t_line line, int deltaX, int deltaY, t_fdf fdf);
void			swap_p(t_line *line, int *sign, int *signZ);

/*fdf_iso.c*/
// void			mlx_pixel_put_iso(int x, int y, int z, t_mlx mlx, int i);
t_point			point_make_iso(int x, int y, int z, int step);
void			line_make_iso(t_line *line, int step, int iso);

/*fdf_read.c*/
void			create_map(t_fdf *fdf, char ***arr);
void			read_me(int fd, t_fdf *fdf);

/*fdf_main.c*/
void			draw(int i, int j, t_fdf *fdf);
void			try_(t_fdf *fdf);
int				main(int ac, char **av);

/*fdf_set.c*/
void 			set_(int fd, t_fdf *fdf);
void			set_mlx(t_fdf *fdf, int width, int height);
int				key_controls(int key, t_fdf *fdf);
void			ft_err(char *err, int status);

/*fdf_clean.c*/
void			clean_map(int ***map, int rows);
void			cleaner(char ****s);

#endif