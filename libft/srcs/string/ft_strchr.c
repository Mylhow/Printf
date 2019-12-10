/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 03:07:34 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 20:23:08 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The strchr() function locates the first occurrence of c in the string
** pointed to by s.
*/

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr((const void *)s, c, ft_strlen(s) + 1));
}
