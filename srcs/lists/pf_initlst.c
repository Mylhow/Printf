/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_initlst.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:12:37 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:28:06 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_initlst(va_list *ap, t_pf *tpf)
{
	tpf->ap = ap;
	tpf->fmoins = FALSE;
	tpf->fprecision = FALSE;
	tpf->vprecision = 0;
	tpf->fstars = FALSE;
	tpf->fzero = FALSE;
	tpf->specifier = ' ';
	tpf->width = 0;
}
