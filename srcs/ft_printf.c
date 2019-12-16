/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 02:40:13 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:32:28 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list ap;
	int		i;
	t_pf	*tpf;

	i = 0;
	if (!(tpf = pf_newlst(&ap)))
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			pf_initlst(&ap, tpf);
			i += pf_conv(tpf, str + i + 1);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			tpf->length++;
		}
		i++;
	}
	va_end(ap);
	return (tpf->length);
}
