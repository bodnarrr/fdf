typedef struct	s_fdflist
{
	t_pts		*points;
	t_fdflist	*next;
}				t_fdflist;

typedef struct	s_pts
{
	int			x;
	int			y;
	int			z;
}				t_fdflist;


int				main(int ac, char **av)
{
	t_fdflist	*map;
	int			lines

	fd = open(av[1], O_RDONLY);
	lines = 0;
	map = ft_parse_map(fd, &lines);
}

t_fdflist	*ft_parse_map(int fd, int *lines)
{
	int			pts_first_row;
	int			pts_curr_row;
	int			rows;
	char		*row;
	char		**splitted;
	t_fdflist	*head;
	t_fdflist	*curr;
	t_fdflist	*prev;
	int			i;

	rows = 0;
	head = NULL;
	prev = NULL;
	while (get_next_line(fd, &row))
	{
		if (rows == 0)
		{
			pts_first_row = ft_get_numbers_of_pts(row);
			pts_curr_row = pts_first_row;
		}
		else
			pts_curr_row = ft_get_numbers_of_pts(row);
		if (pts_curr_row != pts_first_row)
		{
			ft_printf("Incorrect map\n");
			return (NULL);
		}
		curr = ft_func_alloc_new_elem(pts_curr_row);
		if (prev)
			prev->next = curr;
		if (rows == 0)
			head = curr;
		splitted = ft_strsplit(row);
		while (*splitted)
		{
			i = 0;
			while (i < pts_curr_row)
			{
				((curr->points)[i])->z = ft_atoi(*splitted);
				i++;
			}
		}
		prev = curr;
		*lines++;
		ft_strdel(&line);
		ft_func_for_free_splitted(&splitted);
	}
	ft_strdel(&line);
	return (head);
}

