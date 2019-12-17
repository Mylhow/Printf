/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 15:05:40 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 22:11:47 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void		disp_int_show_fmoins(t_pf *tpf, char *base, long val)
{
	if (val < 0)
	{
		val *= -1;
		ft_putchar_fd('-', 1);
	}
	else if (tpf->fplus)
		ft_putchar_fd('+', 1);
	if (tpf->fdiese && val != 0)
		(tpf->specifier == 'x') ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0X", 1);
	ft_putcharec_fd('0', tpf->zero, 1);
	if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
		ft_putnbr_ul_base_fd(val, 1, base);
	ft_putcharec_fd(' ', tpf->whitespace, 1);
}

static void		disp_int_show_no_fmoins(t_pf *tpf, char *base, long val)
{
	ft_putcharec_fd(' ', tpf->whitespace, 1);
	if (tpf->fdiese && val != 0)
		(tpf->specifier == 'x') ? ft_putstr_fd("0x", 1) : ft_putstr_fd("0X", 1);
	if (val < 0)
	{
		val *= -1;
		ft_putchar_fd('-', 1);
	}
	else if (tpf->fplus)
		ft_putchar_fd('+', 1);
	ft_putcharec_fd('0', tpf->zero, 1);
	if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
		ft_putnbr_ul_base_fd(val, 1, base);
}

static void		disp_int_2(t_pf *tpf, char *base, long val)
{
	if (tpf->fdiese || tpf->fplus)
	{
		if (tpf->fplus && val >= 0)
			length_calc(tpf, 1, 1);
		else if (tpf->fdiese && val != 0)
			length_calc(tpf, 1, 2);
		if (tpf->width > tpf->vprecision)
		{
			if (tpf->fplus)
			{
				(val >= 0) ? tpf->whitespace -= 1 : 0;
				(tpf->fzero) ? tpf->zero -= 1 : 0;
			}
			else if (tpf->fdiese && val != 0)
			{
				tpf->whitespace -= 2;
				tpf->zero -= 2;
			}
		}
	}
	if (tpf->fmoins == FALSE)
		disp_int_show_no_fmoins(tpf, base, val);
	else
		disp_int_show_fmoins(tpf, base, val);	
}

void			disp_int(t_pf *tpf, char *base)
{
	long	val;
	int		argsize;

	if (ft_charstr(tpf->specifier, "xX"))
		val = va_arg(*(tpf->ap), long);
	else if (tpf->specifier == 'u')
		val = va_arg(*(tpf->ap), unsigned long);
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
	if (tpf->fspace && tpf->whitespace <= 0 && val >= 0)
	{
		(tpf->whitespace < 0) ? tpf->whitespace = 0 : 0;
		tpf->whitespace++;
		(tpf->fzero > 0) ? tpf->zero-- : 0; 
	}
	length_calc(tpf, 3, tpf->whitespace, tpf->zero, argsize);
	disp_int_2(tpf, base, val);
}
