/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strichr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 09:33:38 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 09:33:52 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strichr(const char *str, int charset)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == charset)
			return (i + 1);
	}
	return (0);
}
