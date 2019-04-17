/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:16:28 by aillia            #+#    #+#             */
/*   Updated: 2019/04/16 14:16:32 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void 	mlx_pixel_put_iso(int x, int y, int z, void *mlx, void *win, int i)
// {
// 	int x_iso;
// 	int y_iso;

// 	x_iso = x - y * cos(0.523599);
// 	y_iso = (x + y) * sin(0.523599) - z;
//     mlx_pixel_put(mlx, win, x_iso + 400, y_iso, i);
// }

t_point	point_make_iso(int x, int y, int z, int step)
{
	t_point p_iso;

	p_iso.x = x - y * cos(0.523599);
	p_iso.y = (x + y) * sin(0.523599) - (z * step/10);
	p_iso.z = z * step/10;
	return (p_iso);
}

void	line_make_iso(t_line *line, int step, int iso)
{
	if (iso == 1)
	{
		line->start = point_make_iso(line->start.x, line->start.y, line->start.z, step);
		line->end = point_make_iso(line->end.x, line->end.y, line->end.z, step);
	}
}