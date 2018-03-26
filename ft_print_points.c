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
			PT.xn = PT.xn * cos(angle) + PT.zn * sin(angle);
			PT.zn = -PT.xn * sin(angle) + PT.zn * cos(angle);
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
			PT.xn = PT.x;
			PT.yn = PT.y * cos(angle) + PT.z * sin(angle);
			PT.zn = -PT.y * sin(angle) + PT.z * cos(angle);
		}
	}
}

void plot_line (int x0, int y0, int x1, int y1, t_fdf *fdf, uint color)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, color);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}

static void	ft_project_points(t_fdf *fdf)
{
	ft_fdf_rot_x(fdf, -40 * DEG);
	ft_fdf_rot_y(fdf, -40 * DEG);
	ft_fdf_rot_z(fdf, 0 * DEG);
}

void		ft_print_points(t_fdf *fdf)
{
	int	i;
	int	j;

	i = -1;
	ft_project_points(fdf);
	while (++i < fdf->rows)
	{
		j = -1;
		while (++j < fdf->cols)
		{
			if (j + 1 < fdf->cols)
				plot_line((fdf->points)[i][j].xn + fdf->sh_hor, (fdf->points)[i][j].yn + fdf->sh_vert,
					(fdf->points)[i][j + 1].xn + fdf->sh_hor, (fdf->points)[i][j + 1].yn + fdf->sh_vert, fdf, (fdf->points)[i][j].clr);
			if (i + 1 < fdf->rows)
				plot_line((fdf->points)[i][j].xn + fdf->sh_hor, (fdf->points)[i][j].yn + fdf->sh_vert,
					(fdf->points)[i + 1][j].xn + fdf->sh_hor, (fdf->points)[i + 1][j].yn + fdf->sh_vert, fdf, (fdf->points)[i][j].clr);
		}
	}
}
