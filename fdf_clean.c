/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:23:15 by aillia            #+#    #+#             */
/*   Updated: 2019/04/17 11:23:30 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_map(int ***map, int rows)
{
	int i;

	i = -1;
	while (++i <= rows)
		free(map[0][i]);
	free(map[0]);
}

void	cleaner(char ****s)
{
	int i;
	int j;
	int k;

	i = -1;
	while (s[0][++i])
	{
		j = -1;
		while (s[0][i][++j])
		{
			free(s[0][i][j]);
		}
		free(s[0][i]);
	}
	free(s[0]);
}