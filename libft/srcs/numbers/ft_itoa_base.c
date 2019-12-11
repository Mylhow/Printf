/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nlecaill <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 13:32:58 by nlecaill     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 13:40:15 by nlecaill    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int		ft_lenght(int n, int base)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int n, char *charset)
{
	char	*str;
	int		i;
	int		sign;
	int		base;

	base = ft_strlen(charset);	
	sign = 1;
	i = ft_lenght(n, base);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		sign = -1;
	}
	str[i] = '\0';
	i--;
	if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = charset[(n % base) * sign];
		n = n / base;
		i--;
	}
	return (str);
}
