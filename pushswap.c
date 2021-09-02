/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:40:28 by graja             #+#    #+#             */
/*   Updated: 2021/08/27 19:18:51 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_sortit(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) > 50)
		ft_fastsort(head_a, head_b);
	else if (ft_lstsize(*head_a) > 3)
		ft_sort(head_a, head_b);
	else
		ft_minisort(head_a, head_b);
}

int	main(int argc, char **argv)
{
	t_list	**head_a;
	t_list	**head_b;
	int		err;

	err = 0;
	if (argc == 1)
		err = -1;
	head_a = malloc(sizeof(t_list *));
	head_b = malloc(sizeof(t_list *));
	if (!head_a || !head_b)
		err = 1;
	if (!err)
	{
		*head_a = NULL;
		*head_b = NULL;
		err = ft_fill_list(head_a, argc, argv);
	}
	if (err > 0)
		write(2, "Error\n", 6);
	if (!err && !ft_issorted(head_a, 0))
		ft_sortit(head_a, head_b);
	ft_cleanup(head_a, head_b);
	return (0);
}
