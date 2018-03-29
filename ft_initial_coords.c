/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_coords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:53:41 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/26 10:53:42 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_one_line(t_fpts **points, t_fdf *fdf)
{
	int	i;
	int space;

	i = -1;
	if (fdf->rows == 1)
	{
		space = (WIN_W - 2 * IND) / (fdf->cols - 1);
		while (++i < fdf->cols)
		{
			points[0][i].x = IND + i * space;
			points[0][i].y = WIN_H / 2;
		}
	}
	else if (fdf->cols == 1)
	{
		space = (WIN_H - 2 * IND) / (fdf->rows - 1);
		while (++i < fdf->rows)
		{
			points[i][0].x = WIN_W / 2;
			points[i][0].y = IND + i * space;
		}
	}
	return (1);
}

int			ft_initial_coords(t_fpts **points, t_fdf *fdf)
{
	int		i;
	int		j;
	int		hor;
	int		vert;

	if (fdf->cols == 1 && fdf->rows == 1)
	{
		points[0][0].x = WIN_W / 2;
		points[0][0].y = WIN_H / 2;
		return (1);
	}
	else if (fdf->cols == 1 || fdf->rows == 1)
		return (ft_one_line(points, fdf));
	hor = (WIN_W - 2 * IND) / (fdf->cols - 1);
	vert = (WIN_H - 2 * IND) / (fdf->rows - 1);
	i = -1;
	while (++i < fdf->rows && (j = -1) == -1)
		while (++j < fdf->cols)
		{
			points[i][j].x = IND + j * hor;
			points[i][j].y = IND + i * vert;
			points[i][j].clr = 0xFF00;
		}
	return (1);
}
