/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:07:20 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 19:20:36 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static
int	ft_find_min(t_list *lst, int n)
{
	int	min;
	int	i;
	int	poi;

	poi = 0;
	i = 1;
	min = *(int *)(lst->content);
	while (i < n)
	{
		lst = lst->next;
		if (*(int *)(lst->content) < min)
		{
			min = *(int *)(lst->content);
			poi = i;
		}
		i++;
	}
	return (poi);
}

static
void	ft_shiftup(t_list **a, t_list **b, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		ft_rotate(a, b, "ra\n", 1);
		i++;
	}
	ft_push(a, b, "pb\n", 1);
}

static
void	ft_shiftdown(t_list **a, t_list **b, int n)
{
	int	i;

	i = 1;
	while (i <= n)
	{
		ft_rotate(a, b, "rra\n", 1);
		i++;
	}
	ft_push(a, b, "pb\n", 1);
}

static
void	ft_switch_back(t_list **a, t_list **b)
{
	if (*(int *)((*a)->content) > *(int *)((*a)->next->content))
		ft_swap(a, b, "sa\n", 1);
	while (*b)
		ft_push(a, b, "pa\n", 1);
}

void	ft_sort(t_list **a, t_list **b)
{
	int	min;
	int	n;

	n = ft_lstsize(*a);
	while (n > 1)
	{
		n = ft_lstsize(*a);
		if (n == 2)
			break ;
		min = ft_find_min(*a, n);
		if (min == 0)
			ft_push(a, b, "pb\n", 1);
		else if (min < (n / 2))
			ft_shiftup(a, b, min);
		else
			ft_shiftdown(a, b, n - min);
	}
	ft_switch_back(a, b);
	return ;
}
