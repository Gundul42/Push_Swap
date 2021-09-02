/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 16:03:35 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 17:01:53 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_minisort(t_list **a, t_list **b)
{
	while (!ft_issorted(a, 0))
	{
		if (ft_getval(a) > ft_getval(&(*a)->next))
		{
			ft_swap(a, b, "sa\n", 1);
		}
		else
			ft_rotate(a, b, "rra\n", 1);
	}
}
