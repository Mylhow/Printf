/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_disp_perc.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/16 16:55:41 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 12:36:34 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_percent(t_pf *tpf)
{
	int nb_space;

	nb_space = (tpf->width > 0) ? tpf->width - 1 : tpf->width;
	tpf->length += nb_space + 1;
	if (!tpf->fmoins)
	{
		while (nb_space--)
		{
			if (tpf->fzero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		ft_putcharec_fd(' ', nb_space, 1);
	}
}
