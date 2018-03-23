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

	if (ac != 2)
		return (ft_fdf_usage());
	if ((fdf = ft_fparse(open(av[1], O_RDONLY), fdf)) == NULL)
		return (1);
	//test
	ft_printf("here?\n");
	ft_printf("%p\n", fdf);
	ft_printf("%p\n", fdf->points);
	ft_printf("%p\n", (fdf->points)[0]);
	int i = 0;
	int j = 0;
	while (i < fdf->rows)
	{
		j = 0;
		while (j < fdf->cols)
		{
			ft_printf("%d ", ((fdf->points)[i][j]).z);
			j++;
		}
		ft_printf("\n");
		i++;
	}


	//test
	ft_printf("and we are here\n");
	return (0);
}


