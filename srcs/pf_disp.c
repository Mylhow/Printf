/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:43:51 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 00:27:19 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

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
	(value[0] == '\0') ? arglen++ : 0;
	if (tpf->fprecision && tpf->vprecision < arglen)
		tronc = tpf->vprecision;
	else
		tronc = arglen;
	if (tpf->width > 0)
		whitespace = tpf->width - tronc;
	tpf->length += (tronc > 0) ? tronc : 0;
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
}

void    disp_uint(t_pf *tpf)
{
	long val;
	int arglen;
	int espace;
	int zero;
	int show;

	show = 1;
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
}
