/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:10:14 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 19:10:10 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static
int	ft_space(char c)
{
	if (((c >= 8) && (c <= 13)) || (c == 32))
		return (1);
	else
		return (0);
}

long	ft_atol(const char *nptr)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while (ft_space(*nptr))
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		res *= 10;
		res += (*nptr - 48);
		nptr++;
	}
	res *= sign;
	return (res);
}
