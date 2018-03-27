/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:02:19 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/26 13:02:26 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fdf_rotate(t_fdf *fdf, int rot)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (rot == ZU)
		fdf->az += 5;
	else if (rot == ZD)
		fdf->az -= 5;
	else if (rot == XU)
		fdf->ax += 5;
	else if (rot == XD)
		fdf->ax -= 5;
	else if (rot == YU)
		fdf->ay += 5;
	else if (rot == YD)
		fdf->ay -= 5;
	ft_print_points(fdf);
}

static void	ft_fdf_move(t_fdf *fdf, int move)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (move == UP)
		fdf->dy -= 5;
	else if (move == DOWN)
		fdf->dy += 5;
	else if (move == RIGHT)
		fdf->dx += 5;
	else if (move == LEFT)
		fdf->dx -= 5;
	ft_print_points(fdf);
}

int			ft_fdf_hooks(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(1);
	else if (key == 124)
		ft_fdf_move(fdf, RIGHT);
	else if (key == 123)
		ft_fdf_move(fdf, LEFT);
	else if (key == 126)
		ft_fdf_move(fdf, UP);
	else if (key == 125)
		ft_fdf_move(fdf, DOWN);

	else if (key == 0)
		ft_fdf_rotate(fdf, ZU);
	else if (key == 2)
		ft_fdf_rotate(fdf, ZD);
	else if (key == 13)
		ft_fdf_rotate(fdf, XU);
	else if (key == 1)
		ft_fdf_rotate(fdf, XD);

	return (0);
}
