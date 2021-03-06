/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:12:35 by graja             #+#    #+#             */
/*   Updated: 2021/08/28 12:12:21 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_chk_input(char *str, t_list *head)
{
	long	i;
	int		*nbr;

	i = 0;
	while (i < (long)ft_strlen(str))
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	i = ft_atol(str);
	if (i > 2147483647 || i < -2147483648)
		return (1);
	while (head)
	{
		nbr = head->content;
		if (*nbr == (int)i)
			return (1);
		head = head->next;
	}
	return (0);
}

int	ft_fill_list(t_list **head_a, int argc, char **argv)
{
	int	n;
	int	err;
	int	*nbr;

	n = 1;
	err = 0;
	while (!err && n < argc)
	{
		err = ft_chk_input(argv[n], *head_a);
		if (!err)
		{
			nbr = malloc(sizeof(int));
			if (!nbr)
				err = 1;
			else
			{
				*nbr = ft_atoi(argv[n]);
				ft_lstadd_back(head_a, ft_lstnew(nbr));
			}
		}
		n++;
	}
	return (err);
}
