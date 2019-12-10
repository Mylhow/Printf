/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_isprint.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 04:03:52 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 07:58:58 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** The isprint() function tests for any printing character, including space.
*/

int		ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
