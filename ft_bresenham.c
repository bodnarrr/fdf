/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:07:22 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/29 16:07:23 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_initialize_bres(t_bres *wrk, t_fpts from, t_fpts to, t_fdf *fdf)
{
	wrk->x0 = from.xn + fdf->dx;
	wrk->x1 = to.xn + fdf->dx;
	wrk->y0 = from.yn + fdf->dy;
	wrk->y1 = to.yn + fdf->dy;
	wrk->dx = ABS(wrk->x1 - wrk->x0);
	if (wrk->x0 < wrk->x1)
		wrk->sx = 1;
	else
		wrk->sx = -1;
	wrk->dy = -(ABS(wrk->y1 - wrk->y0));
	if (wrk->y0 < wrk->y1)
		wrk->sy = 1;
	else
		wrk->sy = -1;
	wrk->err = wrk->dx + wrk->dy;
}

void		ft_bresenham(t_fpts from, t_fpts to, t_fdf *fdf)
{
	t_bres	wrk;

	ft_bzero(&wrk, sizeof(t_bres));
	ft_initialize_bres(&wrk, from, to, fdf);
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, wrk.x0, wrk.y0, 0xFF00);
		if (wrk.x0 == wrk.x1 && wrk.y0 == wrk.y1)
			break ;
		wrk.e2 = 2 * wrk.err;
		if (wrk.e2 >= wrk.dy)
		{
			wrk.err += wrk.dy;
			wrk.x0 += wrk.sx;
		}
		if (wrk.e2 <= wrk.dx)
		{
			wrk.err += wrk.dx;
			wrk.y0 += wrk.sy;
		}
	}
}
