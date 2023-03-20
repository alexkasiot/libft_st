/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akasiota <akasiota@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 18:49:42 by akasiota      #+#    #+#                 */
/*   Updated: 2023/01/08 17:42:06 by akasiota      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*neo;
	t_list	*neo_st;
	t_list	*neo_end;
	t_list	*neo_sub;

	if (lst == NULL)
		return (NULL);
	neo_sub = f(lst->content);
	neo = ft_lstnew(neo_sub);
	if (neo == NULL)
		return (del(neo_sub), NULL);
	neo_st = neo;
	while (lst->next != NULL)
	{
		lst = lst->next;
		neo_end = neo;
		neo_sub = f(lst->content);
		neo = ft_lstnew(neo_sub);
		if (neo == NULL)
			return (del(neo_sub), ft_lstclear(&neo_st, del), NULL);
		neo_end->next = neo;
	}
	neo = neo_st;
	return (neo);
}
