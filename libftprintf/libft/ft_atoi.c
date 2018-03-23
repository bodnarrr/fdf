/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:07:28 by abodnar           #+#    #+#             */
/*   Updated: 2017/11/07 18:09:56 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int64_t		ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	int					i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}
