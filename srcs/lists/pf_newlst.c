/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_newlst.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 17:13:27 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:39:28 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf	*pf_newlst(va_list *ap)
{
	t_pf	*tpf;

	if	(!(tpf = malloc(sizeof(t_pf))))
		return (NULL);
	tpf->ap = ap;
	tpf->fmoins = FALSE;
	tpf->fprecision = FALSE;
	tpf->vprecision = 0;
	tpf->fstars = FALSE;
	tpf->fzero = FALSE;
	tpf->specifier = ' ';
	tpf->width = 0;
	tpf->length	= 0;
	return (tpf);
}
