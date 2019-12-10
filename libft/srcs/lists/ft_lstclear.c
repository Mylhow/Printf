/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear_bonus.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/29 13:12:24 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 20:21:56 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

static void	lstclear(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		lstclear(lst->next, del);
	ft_lstdelone(lst, del);
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	lstclear(*lst, del);
	*lst = 0;
}
