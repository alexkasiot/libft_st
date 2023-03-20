/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/04 18:45:23 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:41:55 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*sub;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	while ((*lst)->next != NULL)
	{
		sub = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = sub;
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
