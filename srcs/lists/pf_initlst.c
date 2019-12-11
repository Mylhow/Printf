/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_initlst.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:12:37 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 16:20:33 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_initlst(va_list *ap, t_pf *tpf)
{
	tpf->ap = ap;
	tpf->fmoins = FALSE;
	tpf->fprecision = FALSE;
	tpf->vprecision = -1;
	tpf->fstars = FALSE;
	tpf->fzero = FALSE;
	tpf->specifier = ' ';
	tpf->width = 0;
}
