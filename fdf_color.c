/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:10:17 by aillia            #+#    #+#             */
/*   Updated: 2019/04/16 14:10:19 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		create_color(int red, int green, int blue)
{
	int color;

	color = 0;
	// if (red > 255)
	// 	red = 255;
	// if (green > 255)
	// 	green = 255;
	// if (blue > 255)
	// 	blue = 255;
	color += red RED;
	color += green GREEN;
	color += blue BLUE;
	return (color);
}