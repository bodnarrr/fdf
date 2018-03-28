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

static t_fdf	*ft_parse_error(t_fdf *fdf, char **line, t_flst **lst)
{
	t_flst		*fordel;
	
	while (*lst)
	{
		fordel = *lst;
		free((*lst)->l_pts);
		*lst = (*lst)->next;
		free(fordel);
		fordel = NULL;
	}
	free(fdf);
	ft_strdel(line);
	ft_printf("Incorrect map!\n");
	system("leaks fdf");
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

t_fdf			*ft_empty_first_line(t_fdf *fdf, char **wrk)
{
	free(wrk[0]);
	wrk[0] = NULL;
	free(wrk);
	wrk = NULL;
	free(fdf);
	fdf = NULL;
	ft_printf("Empty map!\n");
	return (fdf);
}

t_fdf			*ft_fparse(int fd, t_fdf *fdf)
{
	int			gnl;
	t_fparse	p;
	char		**wrk;
	t_fpts		*l_pts;
	t_flst		*lst;

	if (fd == -1)
		return (NULL);
	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	fdf->rows = 0;
	lst = NULL;
	gnl = 0;
	while ((gnl = get_next_line(fd, &(p.line))) == 1)
	{
		wrk = ft_strsplit(p.line, ' ');
		ft_strdel(&(p.line));
		if (fdf->rows == 0)
		{
			if ((p.dotpl = ft_count_dotpl(wrk)) == 0)
				return (ft_empty_first_line(fdf, wrk));
			fdf->cols = p.dotpl;
		}
		p.curr_dotpl = ft_count_dotpl(wrk);
		if (p.curr_dotpl != p.dotpl)
			return (ft_parse_error(fdf, &(p.line), &lst));
		l_pts = ft_make_arr(wrk, p);
		ft_clear_strarr(wrk, p.curr_dotpl);
		lst = ft_add_fnode(l_pts, lst);
		(fdf->rows)++;
	}
	if (gnl == -1)
	{
		ft_printf("It's a folder!\n");
		return (NULL);
	}
	if (p.line != NULL)
		ft_strdel(&(p.line));
	close(fd);
	fdf->points = ft_all_points(lst, fdf);
	return (fdf);
}
