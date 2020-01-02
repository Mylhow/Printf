/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftenum.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:56:07 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 22:42:05 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTENUM_H
# define LIBFTENUM_H

enum	e_boolean
{
	FALSE = 0,
	TRUE = 1
};

enum	e_base
{
	BASE10 = 0,
	BASE16U = 1,
	BASE16l = 2
};

char			*ft_sbase(enum e_base b);
#endif
