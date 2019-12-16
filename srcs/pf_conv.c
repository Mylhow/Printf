/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_conv.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 14:36:07 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 18:04:08 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_conv4(t_pf *tpf, int i)
{
	if (tpf->specifier == 'd' || tpf->specifier == 'i' || tpf->specifier == 'u')
		disp_int(tpf, ft_sbase(BASE10));
	else if (tpf->specifier == 's')
		disp_str(tpf);
	if (tpf->specifier == 'c')
		disp_char(tpf);
	else if (tpf->specifier == 'x')
		disp_int(tpf, ft_sbase(BASE16l));
	else if (tpf->specifier == 'X')
		disp_int(tpf, ft_sbase(BASE16U));
	else if (tpf->specifier == '%')
		disp_percent(tpf);
	else if (tpf->specifier == 'p')
		disp_ptr(tpf, ft_sbase(BASE16l));
	return (i);
}

int	pf_conv3(t_pf *tpf, const char *format, int i)
{
	if (format[i] == '.')
	{
		tpf->fprecision = TRUE;
		tpf->fzero = FALSE;
		i++;
		if (format[i] == '*')
		{
			tpf->vprecision = va_arg(*(tpf->ap), int);
			i++;
			if (tpf->vprecision < 0)
			{
				tpf->vprecision = 0;
				tpf->fprecision = 0;
			}
		}
		else if (ft_isdigit(format[i]))
		{
			tpf->vprecision = ft_atoi(format + i);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	tpf->specifier = format[i++];
	return (pf_conv4(tpf, i));
}

int	pf_conv2(t_pf *tpf, const char *format, int i)
{
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
		tpf->width = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	return (pf_conv3(tpf, format, i));
}

int	pf_conv(t_pf *tpf, const char *format)
{
	int	i;

	i = 0;
	while (format[i] == '-')
	{
		tpf->fmoins = TRUE;
		i++;
	}
	while (format[i] == '0')
	{
		tpf->fzero = TRUE;
		i++;
	}
	return (pf_conv2(tpf, format, i));
}
