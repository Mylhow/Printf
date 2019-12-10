/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_s.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 07:45:08 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 21:14:46 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define RED printf("\033[31m");
#define GREEN printf("\033[32m");
#define BLUE printf("\033[34m");
#define YELLOW printf("\033[33m");
#define MAGENTA printf("\033[35m");
#define CYAN printf("\033[37m");

#define BOLD printf("\033[1m");
#define NORMAL printf("\033[0m");

int	main(void)
{
	printf("%%[\033[32mflags\033[0m]");
	printf("[\033[34mwidth\033[0m]");
	printf("[\033[35m.precision\033[0m]");
	printf("[\033[33mlength\033[0m]");
	printf("\033[31mspecifier\033[0m\n");

	int off, pers;
	(void) pers;
	BLUE BOLD
	printf("============ s ============\n");
	printf("===========================\n");
	NORMAL BOLD RED

	printf("[15s {Hello}] =================\n");
	NORMAL
	pers = ft_printf("'%15s'", "Hello");
	printf("[%d]\n", pers);
	off = printf("'%15s'", "Hello");
	printf("[%d]\n", off);
	NORMAL BOLD RED

    printf("[15s {Chapeau}] =================\n");
	NORMAL
	pers = ft_printf("'%15s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%15s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15s {Hello}] =================\n");
	NORMAL
	pers = ft_printf("'%.15s'", "Hello");
	printf("[%d]\n", pers);
	off = printf("'%.15s'", "Hello");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15s {Chapeau}] ================\n");
	NORMAL
	pers = ft_printf("'%.15s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%.15s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15s {Hello}] =================\n");
	NORMAL
	pers = ft_printf("'%10.15s'", "Hello");
	printf("[%d]\n", pers);
	off = printf("'%10.15s'", "Hello");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15s {Chapeau}] ================\n");
	NORMAL
	pers = ft_printf("'%10.15s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%10.15s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15s {Hello}] =================\n");
	NORMAL
	pers = ft_printf("'%19.15s'", "Hello");
	printf("[%d]\n", pers);
	off = printf("'%19.15s'", "Hello");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15s {Chapeau}] ================\n");
	NORMAL
	pers = ft_printf("'%19.15s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%19.15s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {Hello}] =================\n");
	NORMAL
	pers = ft_printf("'%19.0s'", "Hello");
	printf("[%d]\n", pers);
	off = printf("'%19.0s'", "Hello");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {Chapeau}] ================\n");
	NORMAL
	pers = ft_printf("'%19.0s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%19.0s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[TEST] ================\n");
	NORMAL
	pers = ft_printf("'%-10.3s'", "Chapeau");
	printf("[%d]\n", pers);
	off = printf("'%-10.3s'", "Chapeau");
	printf("[%d]\n", off);
	NORMAL BOLD RED

	BLUE BOLD
	printf("===========================\n");
	NORMAL
	return (0);

}
