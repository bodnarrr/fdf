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

static void	ft_fdf_move(t_fdf *fdf, int move)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	if (move == UP)
		fdf->sh_vert -= 5;
	else if (move == DOWN)
		fdf->sh_vert += 5;
	else if (move == RIGHT)
		fdf->sh_hor += 5;
	else if (move == LEFT)
		fdf->sh_hor -= 5;
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
	return (0);
}