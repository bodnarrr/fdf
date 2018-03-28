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

void	ft_initial_coords(t_fpts **points, int rows, int cols)
{
	int		i;
	int		j;
	int		hor;
	int		vert;

	if (!points)
		return ;
	i = -1;
	hor = (WIN_W - 2 * IND) / (cols - 1);
	vert = (WIN_H - 2 * IND) / (rows - 1);
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
		{
			points[i][j].x = IND + j * hor;
			points[i][j].y = IND + i * vert;
			points[i][j].clr = 0xFF00;
		}
	}
}
