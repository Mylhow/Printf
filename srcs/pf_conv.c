/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_conv.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 14:36:07 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 00:28:48 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int   pf_conv(t_pf *tpf, const char *format)
{
	int     i;
	int		ret;

	i = 0;
	ret = 0;
	while (format[i] == '-') //On avance tant qu'il y a des '-'
	{
		tpf->fmoins = TRUE;
		i++;
	}
	while (format[i] == '0') //On avance tant que l'on a des zeros
	{
		tpf->fzero = TRUE;
		i++;
	}
	if (format[i] == '*')
	{
		tpf->width = va_arg(*(tpf->ap), int);
		if (tpf->width < 0)
		{
			tpf->fmoins = TRUE;
			tpf->width *= -1;
		}
		i++;
	} 
	else
	{
		tpf->width = ft_atoi(format + i); // On recupere la valeur du nombre de caractere a afficher
		while (ft_isdigit(format[i]))
			i++;
	}
	if (format[i] == '.') // On check si il y a un point
	{
		tpf->fprecision = TRUE;
		tpf->fzero = FALSE; //NOTE corrige l'erreur pour printf("%015.13d", xXx);
		i++;
		if (format[i] == '*')
		{
			tpf->vprecision = va_arg(*(tpf->ap), int);
			i++;
		}
		else
		{
			tpf->vprecision = ft_atoi(format + i);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	tpf->specifier = format[i++];
	if (tpf->specifier == 'd' || tpf->specifier == 'i')
	{
		disp_int(tpf);
	}
	else if (tpf->specifier == 'u')
		disp_uint(tpf);
	else if (tpf->specifier == 's' || tpf->specifier == 'c')
	{
		disp_char(tpf);
	}
	
	return (i);
}
