/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:05:40 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:32:31 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		disp_int_2(t_pf *tpf, char *base, long val)
{
	if (tpf->fmoins == FALSE)
	{
		ft_putcharec_fd(' ', tpf->whitespace, 1);
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		ft_putcharec_fd('0', tpf->zero, 1);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_base_fd(val, 1, base);
	}
	else
	{
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		ft_putcharec_fd('0', tpf->zero, 1);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_base_fd(val, 1, base);
		ft_putcharec_fd(' ', tpf->whitespace, 1);
	}
}

void			disp_int(t_pf *tpf, char *base)
{
	long	val;
	int		argsize;

	if (ft_strstr(&tpf->specifier, "uxX"))
		val = va_arg(*(tpf->ap), long);
	else
		val = va_arg(*(tpf->ap), int);
	argsize = ft_digit_base(val, base);
	tpf->zero = (tpf->vprecision < 0) ? 0 : tpf->vprecision - argsize;
	(tpf->vprecision > argsize && val < 0) ? tpf->zero++ : 0;
	tpf->whitespace = pf_prec(tpf, val, argsize);
	if (tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0)
	{
		tpf->length--;
		tpf->whitespace++;
	}
	if (tpf->fzero && tpf->width > tpf->vprecision)
	{
		(tpf->whitespace > 0) ? tpf->zero += tpf->whitespace : 0;
		tpf->whitespace = 0;
	}
	length_calc(tpf, 3, tpf->whitespace, tpf->zero, argsize);
	disp_int_2(tpf, base, val);
}
