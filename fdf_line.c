/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:11:29 by aillia            #+#    #+#             */
/*   Updated: 2019/04/16 14:11:35 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void swap_p(t_line *line, int *sign, int *signZ)
{
	t_point tmp;

	tmp = line->end;
	line->end = line->start;
	line->start = tmp;
	*sign = -*sign;
	*signZ = -*signZ;
}

void line_Xbigger(t_line line, int deltaX, int deltaY, t_fdf fdf)
{
	int error = deltaX - deltaY;
	int signY = line.start.y < line.end.y ? 1 : -1;
	int signZ = line.start.z < line.end.z ? 1 : -1;

	if (line.start.x > line.end.x)
		swap_p(&line, &signY, &signZ);
	while (line.start.x <= line.end.x)
	{
	    // mlx_pixel_put(mlx, win, line.start.x + 400, line.start.y, i + (line.start.z*10));
	    mlx_pixel_put(fdf.mlx.mlx_ptr, fdf.mlx.win_ptr, line.start.x + fdf.margin, line.start.y, create_color(80 + line.start.z * (fdf.step / fdf.color_coef), 200, 175 - line.start.z * (fdf.step / fdf.color_coef)));

		error -= deltaY;
        if (error < 0)
        {
            line.start.y += signY;
            error += deltaX;
            if (line.start.z != line.end.z)
            	line.start.z +=signZ;
        }
		line.start.x++;
	}
}

void line_Ybigger(t_line line, int deltaX, int deltaY, t_fdf fdf)
{
	int error = deltaX - deltaY;
	int signX = line.start.x < line.end.x ? 1 : -1;
	int signZ = line.start.z < line.end.z ? 1 : -1;

	if (line.start.y > line.end.y)
		swap_p(&line, &signX, &signZ);
	while (line.start.y <= line.end.y)
	{
	    // mlx_pixel_put(mlx, win, line.start.x + 400, line.start.y, i  + (line.start.z*10));
	    mlx_pixel_put(fdf.mlx.mlx_ptr, fdf.mlx.win_ptr, line.start.x + fdf.margin, line.start.y,  create_color(80 + line.start.z * (fdf.step / fdf.color_coef), 200, 175 - line.start.z * (fdf.step / fdf.color_coef)));

		error -= deltaX;
        if (error < 0)
        {
            line.start.x += signX;
            error += deltaY;
            if (line.start.z != line.end.z)
            	line.start.z +=signZ;
        }
		line.start.y++;
	}
}

void put_line(t_line line, t_fdf fdf)
{
	int deltaX = abs(line.end.x - line.start.x);
	int deltaY = abs(line.end.y - line.start.y);

	if (deltaX > deltaY)
		line_Xbigger(line, deltaX, deltaY, fdf);
	else
		line_Ybigger(line, deltaX, deltaY, fdf);	
}