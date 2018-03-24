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

int		ft_fdf_usage(void)
{
	ft_printf("usage: ./fdf source_file\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_fdf	*fdf;
	int		fd;
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2)
		return (ft_fdf_usage());
	if ((fdf = ft_fparse(open(av[1], O_RDONLY), fdf)) == NULL)
		return (1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "FDF Mother fucker!");
	// ft_m
	mlx_pixel_put(mlx_ptr, win_ptr, WIN_W / 2, WIN_H / 2, 0xFF00);
	mlx_string_put(mlx_ptr, win_ptr, WIN_W / 2,
							WIN_H / 2, 0xFF00, "It's my FDF, motherfuckers!");
	mlx_loop(mlx_ptr);
	return (0);
}


