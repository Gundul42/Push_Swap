/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fastsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:51:53 by graja             #+#    #+#             */
/*   Updated: 2021/08/22 17:55:57 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_getchunk(int n)
{
	if (n < 200)
		return (4);
	else
		return (9);
}

static void	ft_finish(t_list **a, t_list **b, int *arr, int *max)
{
	ft_chunk_corr(a, b);
	ft_push_back(a, b);
	if (arr)
		free(arr);
	if (max)
		free(max);
}

void	ft_fastsort(t_list **a, t_list **b)
{
	int	n;
	int	chunk;
	int	*arr;
	int	i;
	int	*minmaxlast;

	i = 0;
	n = ft_lstsize(*a);
	chunk = ft_getchunk(n);
	minmaxlast = malloc(sizeof(int) * 3);
	arr = ft_init(a);
	while (arr && minmaxlast && i < chunk)
	{
		minmaxlast[0] = arr[n - (n / chunk) * (i + 1)];
		minmaxlast[1] = arr[(n - (n / chunk) * i) - 1];
		ft_push2b(a, b, minmaxlast, n / chunk);
		if (i)
			ft_shift_back(a, minmaxlast[2]);
		ft_push_back(a, b);
		minmaxlast[2] = ft_getval(a);
		i++;
	}
	ft_finish(a, b, arr, minmaxlast);
}
