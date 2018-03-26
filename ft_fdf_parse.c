/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:14:49 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/22 17:14:50 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_fdf	*ft_parse_error(void)
{
	return (NULL);
}

static t_fpts	**ft_all_points(t_flst *lst, t_fdf *fdf)
{
	int			i;
	t_flst		*wrk;
	t_fpts		**res;

	res = (t_fpts**)malloc(sizeof(t_fpts*) * fdf->rows);
	i = -1;
	wrk = lst;
	while (++i < fdf->rows)
	{
		res[i] = wrk->l_pts;
		wrk = wrk->next;
	}
	return (res);
}

static t_flst	*ft_add_fnode(t_fpts *pts, t_flst *lst)
{
	t_flst		*new;
	t_flst		*wrk;

	new = (t_flst*)malloc(sizeof(t_flst));
	new->l_pts = pts;
	new->next = NULL;
	wrk = lst;
	if (wrk)
	{
		while (wrk->next)
			wrk = wrk->next;
		wrk->next = new;
	}
	else
		lst = new;
	return (lst);
}

static t_fpts	*ft_make_arr(char **wrk, t_fparse p)
{
	t_fpts		*res;
	int			i;

	res = (t_fpts*)ft_memalloc(sizeof(t_fpts) * (p.dotpl));
	i = -1;
	while (++i < p.dotpl)
		(res[i]).z = ft_atoi(wrk[i]);
	i = -1;
	return (res);
}

static int		ft_count_dotpl(char **get)
{
	int		res;
	char	**wrk;

	res = 0;
	wrk = get;
	while (*wrk)
	{
		res++;
		wrk++;
	}
	return (res);
}

t_fdf			*ft_fparse(int fd, t_fdf *fdf)
{
	t_fparse	p;
	char		**wrk;
	t_fpts		*l_pts;
	t_flst		*lst;

	if (fd == -1)
		return (NULL);
	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	ft_bzero(&p, sizeof(t_fparse));
	fdf->rows = 0;
	lst = NULL;
	while (get_next_line(fd, &(p.line)))
	{
		wrk = ft_strsplit(p.line, ' ');
		if (fdf->rows == 0)
		{
			p.dotpl = ft_count_dotpl(wrk);
			fdf->cols = p.dotpl;
		}
		p.curr_dotpl = ft_count_dotpl(wrk);
		if (p.curr_dotpl != p.dotpl)
			return (ft_parse_error());
		l_pts = ft_make_arr(wrk, p);
		ft_clear_lines(wrk, p.curr_dotpl);
		lst = ft_add_fnode(l_pts, lst);
		(fdf->rows)++;
	}
	if (p.line != NULL)
		ft_strdel(&(p.line));
	close(fd);
	fdf->points = ft_all_points(lst, fdf);
	return (fdf);
}
