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

t_fdf			*ft_parse_error(t_fdf *fdf, char **line, t_flst **lst, int fd)
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
	close(fd);
	ft_printf("Incorrect map!\n");
	return (NULL);
}

t_fdf			*ft_all_points(t_flst *lst, t_fdf *fdf)
{
	int			i;
	t_flst		*wrk;
	t_fpts		**res;
	t_flst		*fordel;

	res = (t_fpts**)malloc(sizeof(t_fpts*) * fdf->rows);
	i = -1;
	wrk = lst;
	while (++i < fdf->rows)
	{
		fordel = wrk;
		res[i] = wrk->l_pts;
		wrk = wrk->next;
		free(fordel);
	}
	fdf->points = res;
	return (fdf);
}

t_flst			*ft_add_fnode(t_fpts *pts, t_flst *lst)
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

t_fpts			*ft_make_arr(char **wrk, t_fparse p)
{
	t_fpts		*res;
	int			i;

	res = (t_fpts*)ft_memalloc(sizeof(t_fpts) * (p.dotpl));
	i = -1;
	while (++i < p.dotpl)
	{
		(res[i]).z = ft_atoi(wrk[i]);
		if ((res[i]).z != 0)
			(res[i]).s = 1;
		else
			(res[i]).s = 0;
	}
	return (res);
}

t_fdf			*ft_fparse(int fd, t_fdf *fdf, int gnl, t_flst *lst)
{
	t_fparse	p;
	char		**wrk;

	if (fd == -1 && ft_printf("Incorrect filename!\n"))
		return (NULL);
	fdf = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	while ((gnl = get_next_line(fd, &(p.line))) == 1)
	{
		wrk = ft_strsplit(p.line, ' ');
		ft_strdel(&(p.line));
		if (fdf->rows == 0)
		{
			if ((p.dotpl = ft_count_dotpl(wrk)) == 0)
				return (ft_empty_first_line(fdf, wrk, fd));
			fdf->cols = p.dotpl;
		}
		if ((p.curr_dotpl = ft_count_dotpl(wrk)) != p.dotpl)
			return (ft_parse_error(fdf, &(p.line), &lst, fd));
		lst = ft_make_lst(wrk, p, lst, fdf);
	}
	if (gnl == -1 && ft_printf("It's a folder!\n"))
		return (ft_folder_err(&fdf));
	if (p.line != NULL)
		ft_strdel(&(p.line));
	return (ft_all_points(lst, fdf));
}
