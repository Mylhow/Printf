/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 00:57:02 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 11:43:52 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The ft_strdup() function allocates sufficient memory for a copy of the string
** s1, does the copy, and returns a pointer to it
*/

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		sizes1;

	sizes1 = ft_strlen(s1);
	if (!(ptr = malloc((sizes1 + 1) * sizeof(char))))
		return (NULL);
	ft_memcpy(ptr, s1, sizes1 + 1);
	return (ptr);
}
