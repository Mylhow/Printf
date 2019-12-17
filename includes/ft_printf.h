/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 05:36:15 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 21:46:12 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../libft/includes/libft.h"

typedef struct	s_pf
{
	va_list			*ap;
	enum e_boolean	fzero;
	enum e_boolean	fstars;
	enum e_boolean	fmoins;
	enum e_boolean	fprecision;
	enum e_boolean	fdiese;
	enum e_boolean	fplus;
	enum e_boolean	fspace;
	int				vprecision;
	int				width;
	int				whitespace;
	int				zero;
	char			specifier;
	int				length;
}				t_pf;

int				ft_printf(const char *str, ...)
					__attribute__ ((format (printf, 1, 2)));
int				pf_conv(t_pf *tpf, const char *format);
void			pf_initlst(va_list *ap, t_pf *tpf);
void			disp_char(t_pf *tpf);
void			disp_str(t_pf *tpf);
void			disp_int(t_pf *tpf, char *base);
void			disp_ptr(t_pf *tpf, char *base);
void			disp_percent(t_pf *tpf);
int				pf_prec(t_pf *tpf, long val, int argsize);
void			length_calc(t_pf *tpf, int count, ...);
void			init_tab(void);

#endif
