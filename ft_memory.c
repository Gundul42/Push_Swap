/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 08:02:23 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 08:08:50 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_del(void *nbr)
{
	free(nbr);
}

void	ft_cleanup(t_list **a, t_list **b)
{
	ft_lstclear(a, &ft_del);
	ft_lstclear(b, &ft_del);
	free(a);
	free(b);
}
