/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_initlst.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:12:37 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 15:11:21 by dgascon     ###    #+. /#+    ###.fr     */
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
	tpf->whitespace = 0;
	tpf->zero = 0;
	tpf->specifier = ' ';
	tpf->width = 0;
}
