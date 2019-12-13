/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 13:15:36 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 13:40:08 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_prec(t_pf *tpf, long val, int argsize)
{
	int length;

	length = argsize;
	if (tpf->fprecision && tpf->specifier == 's')
    {
		(tpf->vprecision == -1) ? tpf->vprecision = 0 : 0;
       	return (tpf->vprecision < argsize) ? tpf->vprecision : argsize;
	}
	else if (tpf->specifier == 'd' || tpf->specifier == 'u' || tpf->specifier == 'i' || tpf->specifier == 'x' ||
			tpf->specifier == 'X' || tpf->specifier == 'p')
	{
		length = tpf->width;
		length -= (tpf->vprecision <= argsize) ? argsize : tpf->vprecision;
		length -= (tpf->width > tpf->vprecision && tpf->vprecision > argsize && val < 0) ? 1 : 0;

	}
    return (length);
}

char	*sbase(enum e_base b)
{
	char *str[] = {"0123456789", "0123456789ABCDEF", "0123456789abcdef"};
	return (str[b]);
}

void	disp_percent(t_pf *tpf)
{
	int nb_space;

	nb_space = tpf->width;
	tpf->length = nb_space + 1;
	if (!tpf->fmoins)
	{
		while (nb_space--)
		{
			if (tpf->fzero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
	}
	else
	{
		ft_putchar_fd('%', 1);
		while (nb_space--)
		{
			ft_putchar_fd(' ', 1);
		}
	}
}

