/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:40:28 by graja             #+#    #+#             */
/*   Updated: 2021/08/28 14:30:42 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_last_checks(t_list **a, t_list **b)
{
	if (*b || !ft_issorted(a, 0))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

static int	ft_read_stdin(t_list **a, t_list **b)
{
	char	**ptr;
	int		err;

	err = 1;
	ptr = malloc(sizeof(char *));
	if (!ptr)
		err = -1;
	*ptr = NULL;
	while (err > 0)
	{
		err = get_next_line(0, ptr);
		if (err > 0)
			err = ft_check_cmd(a, b, *ptr);
		free(*ptr);
	}
	if (err < 0)
		write(2, "Error\n", 6);
	else
		ft_last_checks(a, b);
	if (ptr)
		free(ptr);
	return (err);
}

int	main(int argc, char **argv)
{
	t_list	**head_a;
	t_list	**head_b;
	int		err;

	err = 0;
	if (argc == 1)
		return (0);
	head_a = malloc(sizeof(t_list));
	head_b = malloc(sizeof(t_list));
	*head_a = NULL;
	*head_b = NULL;
	if (!head_a || !head_b)
		err = 1;
	if (!err)
		err = ft_fill_list(head_a, argc, argv);
	if (err)
		write(2, "Error\n", 6);
	if (!err && argc > 1)
		ft_read_stdin(head_a, head_b);
	ft_cleanup(head_a, head_b);
	return (0);
}
