/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:34:26 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:26:20 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft_put.h"

void	disp_char(t_pf *tpf)
{
	char	value;
	int		whitespace;

	whitespace = 0;
	value = va_arg(*(tpf->ap), int);
	(tpf->width > 0) ? whitespace = tpf->width - 1 : 0;
	length_calc(tpf, 1, whitespace + 1);
	if (tpf->fmoins == FALSE)
	{
		ft_putnchar_fd(' ', whitespace, 1);
		ft_putchar_fd(value, 1);
	}
	else
	{
		ft_putchar_fd(value, 1);
		ft_putnchar_fd(' ', whitespace, 1);
	}
}
