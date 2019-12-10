/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 05:36:15 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 20:19:33 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

enum e_boolean
{
	TRUE = 1,
	FALSE = 0
};
typedef struct  s_pf
{
	va_list *ap;
	enum    e_boolean   fzero;
	enum    e_boolean   fstars;
	enum    e_boolean   fmoins;
	enum    e_boolean	fprecision;
	int		vprecision;
	int     width;
	char    specifier;
	int		length;
}               t_pf;

int		ft_printf(const char *str, ...)
		__attribute__((format(printf, 1, 2)));
t_pf	*pf_newlst(va_list *ap);
int 	pf_conv(t_pf *tpf, const char *format);
void	pf_initlst(va_list *ap, t_pf *tpf);
void	disp_char(t_pf *tpf);
void	disp_int(t_pf *tpf);

#endif
