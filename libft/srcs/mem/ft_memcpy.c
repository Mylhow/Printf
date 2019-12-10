/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 02:24:26 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 20:22:41 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src to memory area
** dst.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*pdst;
	const char	*psrc;

	if (!dst && !src)
		return (NULL);
	pdst = dst;
	psrc = src;
	while (n-- > 0)
		*(pdst + n) = *(psrc + n);
	return (dst);
}
