/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 09:48:01 by graja             #+#    #+#             */
/*   Updated: 2021/08/28 12:11:17 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static
int	ft_rotate_it(t_list **lst, int flag)
{
	t_list	*hlp;

	if (ft_lstsize(*lst) < 2)
		return (1);
	if (!flag)
	{
		hlp = *lst;
		*lst = (*lst)->next;
		ft_lstadd_back(lst, hlp);
		hlp->next = NULL;
	}
	else
	{
		hlp = *lst;
		while (hlp->next->next)
			hlp = hlp->next;
		ft_lstadd_front(lst, ft_lstlast(*lst));
		hlp->next = NULL;
	}
	return (0);
}

static
void	ft_rot_up(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (!ft_strncmp(ptr, "ra", 2))
		err = ft_rotate_it(head_a, 0);
	else if (!ft_strncmp(ptr, "rb", 2))
		err = ft_rotate_it(head_b, 0);
	else if (!ft_strncmp(ptr, "rr", 2))
	{
		err = ft_rotate_it(head_a, 0);
		err = err && ft_rotate_it(head_b, 0);
	}
	if (flag && !err)
		write(1, ptr, 3);
}

static
void	ft_rot_down(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	err;

	err = 0;
	if (!ft_strncmp(ptr, "rra", 3))
		err = ft_rotate_it(head_a, 1);
	else if (!ft_strncmp(ptr, "rrb", 3))
		err = ft_rotate_it(head_b, 1);
	else if (!ft_strncmp(ptr, "rrr", 3))
	{
		err = ft_rotate_it(head_a, 1);
		err = err && ft_rotate_it(head_b, 1);
	}
	if (flag && !err)
		write(1, ptr, 4);
}

void	ft_rotate(t_list **head_a, t_list **head_b, char *ptr, int flag)
{
	int	len;

	len = ft_strlen(ptr);
	if (!len)
		return ;
	if (len == 3)
		ft_rot_up(head_a, head_b, ptr, flag);
	if (len == 4)
		ft_rot_down(head_a, head_b, ptr, flag);
}
