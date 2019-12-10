/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 11:16:58 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 11:19:18 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(int nb)
{
	long value;

	value = 1;
	if (nb < 1)
		return (0);
	while (value * value <= nb)
	{
		if (value * value == nb)
			return (value);
		value++;
	}
	return (0);
}
