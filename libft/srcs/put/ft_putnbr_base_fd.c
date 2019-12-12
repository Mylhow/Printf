/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_base_fd.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 10:58:28 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 20:10:01 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>

void	ft_putnbr_base(long nbr, int fd, char *base)
{
	if (!base || !ft_strlen(base))
		return ;
	if (ft_strichr(base, '+') || ft_strichr(base, '-'))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr / ft_strlen(base))
		ft_putnbr_base(nbr / ft_strlen(base), fd, base);
	ft_putchar_fd(base[nbr % ft_strlen(base)], fd);
}
