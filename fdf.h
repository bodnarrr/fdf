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
# include <stdbool.h>

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
# define ABS(x) (((x) < 0) ? (-1 * (x)) : (x))
# define ERRMAP ft_printf("Incorrect map!\n")

typedef struct		s_bres
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;

}					t_bres;

typedef struct		s_fpts
{
	float			x;
	float			y;
	float			z;
	char			s;
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
int					ft_initial_coords(t_fpts **points, t_fdf *fdf);
void				ft_print_points(t_fdf *fdf);
int					ft_fdf_hooks(int key, t_fdf *fdf);
void				ft_clear_strarr(char **str, int lines);
int					ft_count_dotpl(char **get);
t_fdf				*ft_empty_first_line(t_fdf *fdf, char **wrk, int fd);
t_fdf				*ft_folder_err(t_fdf **fdf);
t_flst				*ft_make_lst(char **wrk, t_fparse p, t_flst *lst,
					t_fdf *fdf);
t_fpts				*ft_make_arr(char **wrk, t_fparse p);
t_flst				*ft_add_fnode(t_fpts *pts, t_flst *lst);
t_fdf				*ft_all_points(t_flst *lst, t_fdf *fdf);
t_fdf				*ft_parse_error(t_fdf *fdf, char **line, t_flst **lst,
					int fd);
void				ft_initialize_bres(t_bres *wrk, t_fpts from, t_fpts to,
					t_fdf *fdf);
void				ft_bresenham(t_fpts from, t_fpts to, t_fdf *fdf);

#endif
