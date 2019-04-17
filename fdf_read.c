/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aillia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:11:15 by aillia            #+#    #+#             */
/*   Updated: 2019/04/16 14:11:20 by aillia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void create_map(t_fdf *fdf, char ***arr)
{
	int **map;
	int i;
	int j;

	map = (int **)malloc(sizeof(int *) * fdf->rows + 1);
	i = -1;
	while (++i <= fdf->rows)
		map[i] = (int *)malloc(sizeof(int ) * fdf->colums);
	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->colums)
			map[i][j] = ft_atoi(arr[i][j]);
	}
	fdf->map = map;
	cleaner(&arr);
}

void read_me(int fd, t_fdf *fdf)
{
	char *line;
	char ***arr;
	int i;

    arr = (char ***)ft_memalloc(sizeof(char **) * (fdf->rows + 1));
	i = -1;
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		arr[i] = ft_strsplit(line, ' ');
		free(line);
	}
	arr[++i] = NULL;
	i = 0;
	while (arr[0][i])
		i++;
	fdf->colums = i;
	create_map(fdf, arr);
}