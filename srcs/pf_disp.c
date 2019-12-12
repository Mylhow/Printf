/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:43:51 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 20:15:09 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//REVIEW mettre %d dans disp_uint

#include "ft_printf.h"
#include <limits.h>

void	disp_char(t_pf *tpf)
{
	char value;
	int whitespace;

	whitespace = 0;
	value = va_arg(*(tpf->ap), int);
	(tpf->width > 0) ? whitespace = tpf->width - 1 : 0;
	tpf->length += whitespace + 1;
	if (tpf->fmoins == FALSE)
	{
		while (whitespace-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(value, 1);
	}
	else
	{
		ft_putchar_fd(value, 1);
		while (whitespace-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	disp_str(t_pf *tpf)
{
	int argsize;
	char *value;
	int tronc;
	int whitespace;

	whitespace = 0;
	if (!(value = va_arg(*(tpf->ap), char *)))
		value = ft_strdup("(null)");
	argsize = ft_strlen(value);
	tronc = pf_prec(tpf, 0, argsize);
	(tpf->width > 0) ? whitespace = tpf->width - tronc : 0;
	tpf->length += (tronc > 0 ) ? tronc : 0;
	tpf->length += (whitespace > 0) ? whitespace : 0;
	if (tpf->fmoins == FALSE)
	{
		while (whitespace-- > 0)
			ft_putchar_fd(' ', 1);
		ft_putnstr_fd(value, tronc, 1);
	}
	else
	{
		ft_putnstr_fd(value, tronc, 1);
		while (whitespace-- > 0)
			ft_putchar_fd(' ', 1);
	}
}
//010.5 -216
//TODO mettre %p dans une autre fonction avec 2 putnbr_base 1unsigned long pour %p et 1 long long pour le reste
void    disp_int(t_pf *tpf, char *base)
{
	long val;
	int argsize;
	int espace;
	int zero;

	if (tpf->specifier == 'u' || tpf->specifier == 'x' || tpf->specifier == 'X' || tpf->specifier == 'p')
		val = va_arg(*(tpf->ap), long);//-216
	else
		val = va_arg(*(tpf->ap), int);//3267
 	argsize = ft_digit_base(val, base);//4
	(tpf->specifier == 'p') ? argsize += 2 : 0;
	zero = (tpf->vprecision < 0) ? 0 : tpf->vprecision - argsize;//-1-3=-4
	(tpf->vprecision > argsize && val < 0) ? zero++ : 0;
	espace = pf_prec(tpf, val, argsize);//0-3=-3
	if (tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0)
	{
		tpf->length--;
		espace++;
	}
	//printf("[%d] [%d] [%d] [%d] [%d]", tpf->fzero, tpf->width, tpf->vprecision, espace, argsize);
	if (tpf->fzero && tpf->width > tpf->vprecision)
	{
		(espace > 0) ? zero += espace : 0;//zero = 4
		espace = 0; //espace = 0
	}
	tpf->length += (zero < 0) ? 0 : zero;
	tpf->length += (espace < 0) ? 0 : espace;
	tpf->length += argsize;
	if (tpf->fmoins == FALSE)
	{
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);
		if (tpf->specifier == 'p')
			ft_putstr_fd("0x", 1);
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_base(val, 1, base);
	}
	else
	{
		if (tpf->specifier == 'p')
			ft_putstr_fd("0x", 1);
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (!(tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0))
			ft_putnbr_base(val, 1, base);
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);   
	}
}