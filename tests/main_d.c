/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_d.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/20 07:45:08 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 18:59:48 by dgascon     ###    #+. /#+    ###.fr     */
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
	int	ret;

	printf("%%[\033[32mflags\033[0m]");
	printf("[\033[34mwidth\033[0m]");
	printf("[\033[35m.precision\033[0m]");
	printf("[\033[33mlength\033[0m]");
	printf("\033[31mspecifier\033[0m\n");
	printf("\n|%c|\n", NULL);
	BLUE BOLD
	printf("===========================\n");
	NORMAL
	return (0);

}
