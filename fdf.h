/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:11:12 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/22 16:11:13 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libftprintf/libftprintf.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_fpts
{
	int				x;
	int				y;
	int				z;
	uint			clr;
}					t_fpts;

typedef struct		s_fdf
{
	t_fpts			**points;
	int				rows;
	int				cols;
}					t_fdf;

typedef struct		s_flst
{
	t_fpts			*l_pts;
	struct s_flst	*next;
}					t_flst;

typedef struct		s_fparse	
{
	char			*line;
	int				dotpl;
	int				curr_dotpl;
}					t_fparse;

t_fdf				*ft_fparse(int fd, t_fdf *fdf);

#endif
