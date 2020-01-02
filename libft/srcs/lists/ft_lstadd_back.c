/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_back.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 12:19:33 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 22:50:50 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *enew)
{
	if (*alst == 0)
		*alst = enew;
	else
		ft_lstlast(*alst)->next = enew;
}
