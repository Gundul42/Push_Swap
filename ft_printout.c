/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:06:07 by graja             #+#    #+#             */
/*   Updated: 2021/08/26 09:29:32 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

void	ft_print_cot(t_list *head, t_list *bhead)
{
	int	*nbr;

	while (head)
	{
		nbr = head->content;
		printf("%12d %16p\n", *nbr, head);
		head = head->next;
	}
	while (bhead)
	{
		nbr = bhead->content;
		printf("                              %12d %16p\n", *nbr, bhead);
		bhead = bhead->next;
	}
}
