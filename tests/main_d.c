/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 07:45:08 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 23:19:03 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

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
	printf("============ d ============\n");
	printf("===========================\n");
	NORMAL BOLD RED

	printf("[15d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%15d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%15d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[15d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%15d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%15d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[15d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%15d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%15d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%.15d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%.15d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%.15d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%.15d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%.15d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%.15d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[.15d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%.15d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%.15d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[15d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%15d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%15d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%10.15d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%10.15d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%10.15d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%10.15d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%10.15d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%10.15d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[10.15d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%10.15d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%10.15d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%19.15d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%19.15d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%19.15d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%19.15d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%19.15d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%19.15d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.15d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%19.15d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%19.15d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%19.0d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%19.0d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%19.0d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%19.0d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%19.0d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%19.0d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[19.0d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%19.0d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%19.0d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[0.0d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%0.0d'", 1);
	printf("[%d]\n", pers);
	off = printf("'%0.0d'", 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[0.0d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%0.0d'", 12);
	printf("[%d]\n", pers);
	off = printf("'%0.0d'", 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[0.0d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%0.0d'", 123);
	printf("[%d]\n", pers);
	off = printf("'%0.0d'", 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[0.0d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("'%0.0d'", 1234);
	printf("[%d]\n", pers);
	off = printf("'%0.0d'", 1234);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[*.*d {1}] =================\n");
	NORMAL
	pers = ft_printf("'%*.*d'", 15, 13, 1);
	printf("[%d]\n", pers);
	off = printf("'%*.*d'", 15, 13, 1);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[*.*d {12}] ================\n");
	NORMAL
	pers = ft_printf("'%*.*d'", 15, 13, 12);
	printf("[%d]\n", pers);
	off = printf("'%*.*d'", 15, 13, 12);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[*.*d {123}] ===============\n");
	NORMAL
	pers = ft_printf("'%*.*d'", 15, 13, 123);
	printf("[%d]\n", pers);
	off = printf("'%*.*d'", 15, 13, 123);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	printf("[ *.*d {1234}] ==============\n");
	NORMAL
	pers = ft_printf("%s", NULL);
	printf("[%d]\n", pers);
	off = printf("%s", NULL);
	printf("[%d]\n", off);
	NORMAL BOLD RED

	BLUE BOLD
	printf("===========================\n");
	NORMAL
	return (0);

}
