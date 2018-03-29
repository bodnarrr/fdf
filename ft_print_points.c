/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:24:57 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/26 11:24:58 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fdf_rot_z(t_fdf *fdf, float angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
		{
			PT.xn = PT.xn * cos(angle) - PT.yn * sin(angle);
			PT.yn = PT.xn * sin(angle) + PT.yn * cos(angle);
		}
	}
}

static void	ft_fdf_rot_y(t_fdf *fdf, float angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
		{
			PT.xn = PT.x * cos(angle) + PT.zn * sin(angle);
			PT.zn = -PT.x * sin(angle) + PT.zn * cos(angle);
		}
	}
}

static void	ft_fdf_rot_x(t_fdf *fdf, float angle)
{
	int	i;
	int	j;

	i = -1;
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
		{
			PT.yn = PT.y * cos(angle) + PT.z * sin(angle);
			PT.zn = -PT.y * sin(angle) + PT.z * cos(angle);
		}
	}
}

static void	ft_project_points(t_fdf *fdf)
{
	ft_fdf_rot_x(fdf, -40 * DEG);
	ft_fdf_rot_y(fdf, -40 * DEG);
	ft_fdf_rot_z(fdf, 5 * DEG);
}

void		ft_print_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	ft_project_points(fdf);
	if (fdf->rows == 1 && fdf->cols == 1)
		mlx_pixel_put(fdf->mlx, fdf->win, (fdf->points)[0][0].x + fdf->dx
			- WIN_W / 5, (fdf->points)[0][0].y + fdf->dy - WIN_H / 8, 0xFF00);
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
		{
			if (j + 1 < fdf->cols)
				ft_bresenham((fdf->points)[i][j], (fdf->points)[i][j + 1], fdf);
			if (i + 1 < fdf->rows)
				ft_bresenham((fdf->points)[i][j], (fdf->points)[i + 1][j], fdf);
		}
	}
	mlx_string_put(fdf->mlx, fdf->win, 550, 20, 0xFF00, "Use arrows for moving \
		the map\n and \"W\", \"S\" for manipulating height of points");
	mlx_string_put(fdf->mlx, fdf->win, 800, 50, 0xFF00, "Space for initial \
		position\n");
}
