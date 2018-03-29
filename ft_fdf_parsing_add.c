/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_parsing_add.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:59:05 by abodnar           #+#    #+#             */
/*   Updated: 2018/03/28 14:59:06 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_count_dotpl(char **get)
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

t_fdf			*ft_empty_first_line(t_fdf *fdf, char **wrk, int fd)
{
	free(wrk[0]);
	wrk[0] = NULL;
	free(wrk);
	wrk = NULL;
	free(fdf);
	fdf = NULL;
	close(fd);
	ft_printf("Empty map!\n");
	return (fdf);
}

t_fdf			*ft_folder_err(t_fdf **fdf)
{
	free(*fdf);
	*fdf = NULL;
	return (*fdf);
}

char			**ft_get_clearsplit(char **str)
{
	char		**res;

	res = ft_strsplit(*str, ' ');
	ft_strdel(str);
	return (res);
}

t_flst			*ft_make_lst(char **wrk, t_fparse p, t_flst *lst, t_fdf *fdf)
{
	t_fpts		*l_pts;

	l_pts = ft_make_arr(wrk, p);
	ft_clear_strarr(wrk, p.curr_dotpl);
	lst = ft_add_fnode(l_pts, lst);
	(fdf->rows)++;
	return (lst);
}
