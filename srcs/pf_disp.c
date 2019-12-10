/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:43:51 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 23:21:08 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

// TODO remplacer foret de If par tableau de pointeur sur fonctions
void disp_cdhar(t_pf *tpf)
{
	int sizeCar;
	char *arg;
	int i;
	int prec_compt;

	i = 0;
	prec_compt = 0;
	if (tpf->specifier == 'c')
	{
		if (!(arg = malloc(2))) //TODO Secu malloc
			return ;
		arg[1] = '\0';
		arg[0] = va_arg(*(tpf->ap), int);
	}
	else
		arg = va_arg(*(tpf->ap), char *);
	sizeCar = ft_strlen(arg);
	if (sizeCar > tpf->width)
		tpf->length += sizeCar;
	else
		tpf->length += tpf->width;

	if ((tpf->fprecision == TRUE) && (tpf->vprecision < sizeCar)) // gestion precision
			i -= sizeCar - tpf->vprecision;
	sizeCar = tpf->width - sizeCar; //sizeCar = 7 - 5
										//sizeCar = 2 verifie ca stp Comment ?
	if (tpf->fmoins == FALSE)
	{
		while (i < sizeCar)
		{

			if (tpf->fzero == FALSE)
				ft_putchar_fd(' ', 1);
			else
				ft_putchar_fd('0', 1);
			i++;
		}
		if (tpf->fprecision)
		   ft_putnstr_fd(arg, tpf->vprecision, 1); //TODO putnstr(char *, int);
		else
			ft_putstr_fd(arg, 1);
	}
	else
	{
		ft_putnstr_fd(arg, tpf->vprecision, 1);
		while (i < sizeCar)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (tpf->specifier == 'c')
		free(arg);
}

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
		value = va_arg(*(tpf->ap), char *);
	if (!value)
	{
		tpf->length += 6;
		ft_putstr_fd("(null)", 1);
		return ;
	}
	arglen = ft_strlen(value);
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
//0.20d 2147483648
void    disp_int(t_pf *tpf)
{
	long val;
	int arglen;
	int espace;
	int zero;

	val = va_arg(*(tpf->ap), int);
	arglen = ft_digit(val);//1
	zero = tpf->vprecision - arglen; // 20-10=10
	if (tpf->vprecision == 0)
		espace = tpf->width - arglen;//45-1=44
	else
		espace = tpf->width - tpf->vprecision;
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
		ft_putnbr_fd(val, 1);
	}
	else
	{
		while (zero-- > 0)
			ft_putchar_fd('0', 1);
		ft_putnbr_fd(val, 1);
		while (espace-- > 0)
			ft_putchar_fd(' ', 1);   
	}
}
