/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:55:44 by graja             #+#    #+#             */
/*   Updated: 2021/08/28 07:40:19 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

void	ft_swap(t_list **head_a, t_list **head_b, char *ptr, int flag);
void	ft_push(t_list **head_a, t_list **head_b, char *ptr, int flag);
void	ft_rotate(t_list **head_a, t_list **head_b, char *ptr, int flag);
void	ft_sort(t_list **a, t_list **b);
int		ft_issorted(t_list **lst, int rev);
int		ft_isposonly(t_list *lst);
int		ft_getval(t_list **lst);
int		ft_getlastval(t_list **lst);
int		ft_getmaxval(t_list **lst);
int		ft_getminval(t_list **lst);
int		ft_upordown(t_list **lst, int max);
void	ft_bubblesort(int *ptr, int n);
void	ft_fastsort(t_list **a, t_list **b);
int		*ft_init(t_list **lst);
int		ft_getshortest(t_list **lst, int min, int max);
void	ft_chunk_corr(t_list **a, t_list **b);
void	ft_shift_back(t_list **lst, int max);
void	ft_push2b(t_list **a, t_list **b, int *max, int n);
void	ft_push_back(t_list **a, t_list **b);
void	ft_putinpos(t_list **lst);
size_t	gnl_strlen(const char *s, int flag);
int		get_next_line(int fd, char **line);
int		ft_check_cmd(t_list **a, t_list **b, char *ptr);
void	ft_cleanup(t_list **a, t_list **b);
int		ft_fill_list(t_list **head_a, int argc, char **argv);
int		ft_chk_input(char *str, t_list *head);
void	ft_minisort(t_list **a, t_list **b);
long	ft_atol(const char *nptr);

#endif
