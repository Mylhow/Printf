/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isdigit.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 01:06:13 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 07:58:49 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The isdigit() function tests for a decimal digit character.
*/

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
