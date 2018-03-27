/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:10:33 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/22 16:10:34 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_initialize_fdf(t_fdf *fdf)
{
	fdf->dx = 0.0;
	fdf->dy = 0.0;
	fdf->ax = 0;
	fdf->ay = 0;
	fdf->az = 0;
	fdf->cx = 0.0;
	fdf->cy = 0.0;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FDF");
	return (fdf);
}

int		ft_fdf_usage(void)
{
	ft_printf("usage: ./fdf source_file\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (ft_fdf_usage());
	fdf = NULL;
	if ((fdf = ft_fparse(open(av[1], O_RDONLY), fdf)) == NULL)
		return (1);
	ft_initial_coords(fdf->points, fdf->rows, fdf->cols);
	fdf = ft_initialize_fdf(fdf);
	ft_print_points(fdf);
	mlx_hook(fdf->win, 2, 5, ft_fdf_hooks, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
