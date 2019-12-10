/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back_bonus.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 12:19:33 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 20:21:46 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (*alst == 0)
		*alst = new;
	else
		ft_lstlast(*alst)->next = new;
}
