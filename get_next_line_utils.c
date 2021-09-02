/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:29:01 by graja             #+#    #+#             */
/*   Updated: 2021/08/24 18:30:43 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	gnl_strlen(const char *s, int flag)
{
	size_t	i;

	i = 0;
	if (flag <= 0)
	{
		while (s[i] != '\0')
			i++;
	}
	else
		while (s[i] != '\0' && s[i] != '\n')
			i++;
	return (i);
}
