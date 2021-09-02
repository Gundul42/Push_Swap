/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:09:59 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 14:01:22 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static
int	ft_swap_it(t_list *head)
{
	int	*hlp;

	if (!head || (ft_lstsize(head) < 2))
		return (1);
	hlp = head->content;
	head->content = head->next->content;
	head->next->content = hlp;
	return (0);
}

void	ft_swap(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (!ft_strncmp(ptr, "sa", 2))
		err = ft_swap_it(*head_a);
	else if (!ft_strncmp(ptr, "sb", 2))
		err = ft_swap_it(*head_b);
	else if (!ft_strncmp(ptr, "ss", 2))
	{
		err = ft_swap_it(*head_a);
		err = err && ft_swap_it(*head_b);
	}
	if (flag && !err)
		write(1, ptr, 3);
}
