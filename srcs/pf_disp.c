/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:43:51 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:11:50 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//REVIEW %d dans disp_uint

#include "ft_printf.h"
#include <limits.h>
#define BASE16G "0123456789ABCDEF"
#define BASE16P "0123456789abcdef"
#define BASE10 "0123456789"

void	disp_char(t_pf *tpf)
{
	int arglen;
	char *value;
	int tronc;
	int whitespace;

	whitespace = 0;
	if (tpf->specifier == 'c')
		value = ft_chartostr(va_arg(*(tpf->ap), int));
	else
	{
		if (!(value = va_arg(*(tpf->ap), char *)))
			value = ft_strdup("(null)");
	}
	arglen = ft_strlen(value);
	(tpf->specifier == 'c' && value[0] == '\0') ? arglen++ : 0; 
	//TODO tester %c 
	if (tpf->fprecision && tpf->vprecision < arglen)
		tronc = tpf->vprecision;
	else
		tronc = arglen;
	if (tpf->width > 0)
		whitespace = tpf->width - tronc;
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
	if (tpf->specifier == 'c')
		free(value);
}

//-2147483648
void    disp_int(t_pf *tpf)
{
	long val;
	int arglen;
	int espace;
	int zero;
	int show;

	show = 1;
	val = va_arg(*(tpf->ap), int);
	arglen = ft_digit(val);
	if (val < 0)
		arglen--;
	zero = tpf->vprecision - arglen; //10-2=8

	if (tpf->vprecision <= 0)
		espace = tpf->width - arglen;
	else
		espace = tpf->width - tpf->vprecision;
	if (tpf->fprecision == 1)
	{
		if (tpf->vprecision == -1 && val == 0)
		{
			tpf->length--;
			show = 0;
			espace++;
		}
		else if (tpf->vprecision == 0 && val == 0)
		{
			tpf->length--;
			show = 0;
			espace++;
		}
	}
	if (tpf->fzero)
	{
		(espace > 0) ? zero += espace : 0;
		if (tpf->vprecision == -1)
		{
			zero += arglen;
			(val > 0) ? zero++ : 0;
		}
		espace = 0;
	}
	if (val < 0)
	{
		arglen++;
		espace--;
	}
	tpf->length += (zero < 0) ? 0 : zero;
	tpf->length += (espace < 0) ? 0 : espace;
	tpf->length += arglen;
	if (tpf->fmoins == FALSE)
	{
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		//printf("*%d*%d", val, show);
		if (show)
		ft_putnbr_fd(val, 1);
	}
	else
	{
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (val < 0)
		{
			val *= -1;
			ft_putchar_fd('-', 1);
		}
		if (show)
		ft_putnbr_fd(val, 1);
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);   
	}
}

void    disp_uint(t_pf *tpf)
{
	long val;
	int arglen;
	int espace;
	int zero;
	int show;
	char *base;

	show = 1;
	if (tpf->specifier == 'x' || tpf->specifier == 'p')
		base = BASE16P;
	else if (tpf->specifier == 'X')
		base = BASE16G;
	else
		base = BASE10;
	val = va_arg(*(tpf->ap), long);
	arglen = ft_digit_base(val, base);
	(tpf->specifier == 'p') ? arglen += 2 : 0;
	zero = tpf->vprecision - arglen; 
	if (tpf->vprecision <= 0)
		espace = tpf->width - arglen;
	else
		espace = tpf->width - tpf->vprecision;
	if (tpf->fprecision == 1 && val == 0 && tpf->vprecision <= 0)
	{
		show = 0;
		espace++;
		tpf->length--;
	}
	if (tpf->fzero)
	{
		if (tpf->specifier == 'x' && val == 0)
			zero+=2;
		(espace > 0) ? zero += espace : 0;
		espace = 0;
	}
	if (val < 0)
	{
		ft_putchar_fd('-', 1);
		val *= -1;
		arglen++;
		(tpf->fmoins) ? espace-- : 0;
	}
	tpf->length += (zero < 0) ? 0 : zero;
	tpf->length += (espace < 0) ? 0 : espace;
	tpf->length += arglen;
	if (tpf->fmoins == FALSE)
	{
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);
		if (tpf->specifier == 'p')
		{
			ft_putstr_fd("0x", 1);
		}
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (show)
		ft_putnbr_base(val, 1, base);
	}
	else
	{
		if (tpf->specifier == 'p')
		{
			ft_putstr_fd("0x", 1);
		}
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (show)
		ft_putnbr_base(val, 1, base);
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);   
	}
}
/*void    disp_uint(t_pf *tpf)
{
	long val;
	int arglen;
	int espace;
	int zero;
	int show;

	show = 1;
	if (tpf->specifier == 'p')
		val = va_arg(*(tpf->ap), long);
	else
		val = va_arg(*(tpf->ap), long);
	arglen = ft_digit(val);
	zero = tpf->vprecision - arglen; 
	if (tpf->vprecision == 0)
		espace = tpf->width - arglen;
	else
		espace = tpf->width - tpf->vprecision;
	if (tpf->fprecision == 1 && val == 0)
	{
		show = 0;
		espace++;
		tpf->length--;
	}
	if (tpf->fzero)
	{
		(espace > 0) ? zero += espace : 0;
		espace = 0;
	}
	if (val < 0)
	{
		ft_putchar_fd('-', 1);
		val *= -1;
		arglen++;
		(tpf->fmoins) ? espace-- : 0;
	}
	tpf->length += (zero < 0) ? 0 : zero;
	tpf->length += (espace < 0) ? 0 : espace;
	tpf->length += arglen;
	if (tpf->fmoins == FALSE)
	{
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (show)
		ft_putnbr_fd(val, 1);
	}
	else
	{
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		if (show)
		ft_putnbr_fd(val, 1);
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);   
	}
}*/
