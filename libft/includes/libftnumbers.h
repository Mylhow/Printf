/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftnumbers.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/20 18:32:02 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 13:46:47 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTNUMBERS_H
# define LIBFTNUMBERS_H

char			*ft_itoa(int n);
char			*ft_itoa_base(int nb, char * charset);
int				ft_digit(long num);
int				ft_digit_base(long num, char *base);
int				ft_digit_ul_base(unsigned long num, char *base);
#endif