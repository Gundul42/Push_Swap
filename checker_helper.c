/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:58:48 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 14:10:14 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_psh(t_list **a, t_list **b, char *ptr)
{
	if (!ft_strncmp(ptr, "pa", 2))
		ft_push(a, b, "pa\n", 0);
	else if (!ft_strncmp(ptr, "pb", 2))
		ft_push(a, b, "pb\n", 0);
	else
		return (-1);
	return (1);
}

static int	ft_swp(t_list **a, t_list **b, char *ptr)
{
	if (!ft_strncmp(ptr, "sa", 2))
		ft_swap(a, b, "sa\n", 0);
	else if (!ft_strncmp(ptr, "sb", 2))
		ft_swap(a, b, "sb\n", 0);
	else if (!ft_strncmp(ptr, "ss", 2))
		ft_swap(a, b, "ss\n", 0);
	else
		return (-1);
	return (1);
}

static int	ft_rtt(t_list **a, t_list **b, char *ptr)
{
	if (!ft_strncmp(ptr, "ra", 2))
		ft_rotate(a, b, "ra\n", 0);
	else if (!ft_strncmp(ptr, "rb", 2))
		ft_rotate(a, b, "rb\n", 0);
	else if (!ft_strncmp(ptr, "rr", 2))
		ft_rotate(a, b, "rr\n", 0);
	else
		return (-1);
	return (1);
}

static int	ft_three(t_list **a, t_list **b, char *ptr)
{
	if (!ft_strncmp(ptr, "rra", 3))
		ft_rotate(a, b, "rra\n", 0);
	else if (!ft_strncmp(ptr, "rrb", 3))
		ft_rotate(a, b, "rrb\n", 0);
	else if (!ft_strncmp(ptr, "rrr", 3))
		ft_rotate(a, b, "rrr\n", 0);
	else
		return (-1);
	return (1);
}

int	ft_check_cmd(t_list **a, t_list **b, char *ptr)
{
	int	len;
	int	err;

	err = 0;
	len = ft_strlen(ptr);
	if (len < 2 || len > 3)
		return (-1);
	if (len == 2)
	{
		if (!ft_strncmp(ptr, "p", 1))
			err = ft_psh(a, b, ptr);
		else if (!ft_strncmp(ptr, "s", 1))
			err = ft_swp(a, b, ptr);
		else if (!ft_strncmp(ptr, "r", 1))
			err = ft_rtt(a, b, ptr);
		else
			return (-1);
	}
	else
		err = ft_three(a, b, ptr);
	return (err);
}
