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
# include <math.h>
# include <stdio.h>

# define WIN_W 1920
# define WIN_H 1080
# define IND 200
# define PT (fdf->points)[i][j]
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define DEG (M_PI / 180)
# define ZU 0
# define ZD 1
# define XU 2
# define XD 3
# define YU 4
# define YD 5

typedef struct		s_fpts
{
	float			x;
	float			y;
	float			z;
	float			xn;
	float			yn;
	float			zn;
	uint			clr;
}					t_fpts;

typedef struct		s_fdf
{
	t_fpts			**points;
	int				rows;
	int				cols;
	float			dx;
	float			dy;
	void			*mlx;
	void			*win;
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

t_fdf				*ft_fparse(int fd, t_fdf *fdf, int gnl, t_flst *lst);
void				ft_initial_coords(t_fpts **points, int rows, int cols);
void				ft_print_points(t_fdf *fdf);
int					ft_fdf_hooks(int key, t_fdf *fdf);
void				ft_clear_strarr(char **str, int lines);

#endif
