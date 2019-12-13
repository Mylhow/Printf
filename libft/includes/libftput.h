/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftput.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <dgascon@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/20 18:32:02 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 13:43:59 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPUT_H
# define LIBFTPUT_H
# include <unistd.h>

void	ft_putnstr_fd(char *str, int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putnbr_base_fd(long nbr, int fd, char *base);
void	ft_putnbr_ul_base_fd(unsigned long nbr, int fd, char *base);
#endif
