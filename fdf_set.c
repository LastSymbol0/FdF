/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_measurement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:09:06 by aillia            #+#    #+#             */
/*   Updated: 2019/04/16 16:09:22 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_controls(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		clean_map(&fdf->map, fdf->rows);
		ft_err("Bye.\n", 0);
	}
	if (key == 115 || key == 119)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->iso = -fdf->iso;
		try_(fdf);
	}
	if (key == 125)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->step -= 5;
		try_(fdf);
	}
	if (key == 126)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->step += 5;
		try_(fdf);
	}
	if (key == 124)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->margin -= 20;
		try_(fdf);
	}
	if (key == 123)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->margin += 20;
		try_(fdf);
	}
	if (key == 78 && fdf->color_coef > 2)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->color_coef -= 2;
		try_(fdf);
	}
	if (key == 69)
	{
		mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		fdf->color_coef += 2;
		try_(fdf);
	}
		printf("~~~~~\nCurrent set:\n\tWindow size: %d x %d\n\tType of projection: %s\n", fdf->mlx.width, fdf->mlx.height, fdf->iso == 1 ? "iso" : "paralel");
		printf("\tStep: %d\n\tLeft margin: %d\n\tColor coef:%d\n", fdf->step, fdf->margin, fdf->color_coef);

	return (1);
}

void set_(int fd, t_fdf *fdf)
{
	int		rows;
	char	*line;

	rows = 1;
	if (get_next_line(fd, &line) != 1)
		ft_err("Empty file", 1);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		rows++;
		free(line);
	}
	fdf->rows = rows;
	fdf->iso = 1;
	fdf->color_coef = 10;
}

void	set_mlx(t_fdf *fdf, int width, int height)
{
	fdf->mlx.width = width;
	fdf->mlx.height = height;
	fdf->mlx.mlx_ptr = mlx_init();
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr, fdf->mlx.width, fdf->mlx.height, "Hello world");
	fdf->margin = (fdf->mlx.width / 2);
	mlx_hook(fdf->mlx.win_ptr, 2, 0, key_controls, fdf);
}

void	ft_err(char *err, int status)
{
	ft_putstr(err);
	exit(status);
}

