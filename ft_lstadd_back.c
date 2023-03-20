/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back_bonus.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 16:41:32 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:41:45 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	int		i;
	t_list	*sub;

	sub = *lst;
	if (*lst == NULL && new == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	i = 0;
	while ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
	}
	(*lst)->next = new;
	*lst = sub;
}
