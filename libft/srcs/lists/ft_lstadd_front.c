/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd_front.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/25 08:23:46 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 11:42:33 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd_front(t_list **alst, t_list *enew)
{
	if (!alst || !enew)
		return ;
	enew->next = *alst;
	*alst = enew;
}
