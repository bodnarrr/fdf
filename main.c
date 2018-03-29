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

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

t_fdf	*ft_initialize_fdf(t_fdf *fdf)
{
	fdf->dx = WIN_W / 5;
	fdf->dy = WIN_H / 8;
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
	int		fd;

	if (ac != 2)
		return (ft_fdf_usage());
	fdf = NULL;
	fd = open(av[1], O_RDONLY);
	if ((fdf = ft_fparse(fd, fdf, 0, NULL)) == NULL)
		return (1);
	ft_initial_coords(fdf->points, fdf);
	fdf = ft_initialize_fdf(fdf);
	ft_print_points(fdf);
	mlx_hook(fdf->win, 2, 5, ft_fdf_hooks, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, exit_x, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
