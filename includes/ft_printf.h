/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 05:36:15 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 05:27:16 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct  s_pf
{
    char    flags;
    size_t  width;
	va_list ap;
    size_t  precision;
    size_t  length;
    char    specifier;
}               t_pf;

int	ft_printf(const char *str, ...) __attribute__((format(printf, 1, 2)));
#endif
