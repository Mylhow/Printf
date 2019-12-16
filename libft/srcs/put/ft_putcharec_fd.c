/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putcharec_fd.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 13:34:24 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 13:49:45 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putcharec_fd(char c, int n, int fd)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, fd);
		i++;
	}
}