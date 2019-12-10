/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isascii.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 03:54:14 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 07:58:09 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The isascii() function tests for an ASCII character, which is any character
** between 0 and octal 0177 inclusive.
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}