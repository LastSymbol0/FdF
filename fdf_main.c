/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:43:42 by aillia            #+#    #+#             */
/*   Updated: 2019/04/13 13:14:13 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(int i, int j, t_fdf *fdf)
{
	t_line to_right;
	t_line to_bot;

	to_right.start.x = j * fdf->step;
	to_right.start.y = i * fdf->step;
	to_right.start.z = fdf->map[i - 1][j - 1];

	to_right.end.x = j * fdf->step + fdf->step;
	to_right.end.y = i * fdf->step;
	to_right.end.z = fdf->map[i - 1][j];

	to_bot.start.x = j * fdf->step;
	to_bot.start.y = i * fdf->step;
	to_bot.start.z = fdf->map[i - 1][j - 1];

	to_bot.end.x = j * fdf->step;
	to_bot.end.y = i * fdf->step + fdf->step;
	to_bot.end.z = fdf->map[i][j - 1];

	line_make_iso(&to_bot, fdf->step, fdf->iso);
	line_make_iso(&to_right, fdf->step, fdf->iso);

	if (i < fdf->rows)
		put_line(to_bot, *fdf);
	if (j < fdf->colums)
		put_line(to_right, *fdf);
}

void	try_(t_fdf *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->colums)
			draw(i + 1, j + 1, fdf);
	}
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac < 2)
		ft_err(USAGE, 0);
	set_(open(av[1], O_RDONLY), &fdf);
	read_me(open(av[1], O_RDONLY), &fdf);
	if (ac > 2)
	{
		if (av[2][0] && ft_isdigit(av[2][0]))
			fdf.step = ft_atoi(av[2]);
		else
			ft_err("Incorrect value for step\n", 1);
	}
	else
		fdf.step = 42;
	set_mlx(&fdf, ac > 3 && ft_isdigit(av[3][0]) ? ft_atoi(av[3]) : 2000,
					ac > 4 && ft_isdigit(av[4][0]) ? ft_atoi(av[4]) : 1200);
	try_(&fdf);
	mlx_loop(fdf.mlx.mlx_ptr);
	return (0);
}
