/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftput.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/20 18:32:02 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2020/01/02 22:38:33 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPUT_H
# define LIBFTPUT_H

void	ft_putnstr_fd(char *str, int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_base_fd(long nbr, int fd, char *base);
void	ft_putnbr_ul_base_fd(unsigned long nbr, int fd, char *base);
void	ft_putcharec_fd(char c, int n, int fd);
void	ft_putnbr_format_fd(long n, int fd);
#endif
