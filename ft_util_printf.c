/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:59:32 by benmoham          #+#    #+#             */
/*   Updated: 2021/10/24 19:54:19 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_putchar(char c, int n)
{
	static int	i = 0;
	int			res;

	res = 0;
	if (n == 1)
	{	
		res = i;
		i = 0;
		return (res);
	}
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putstr(char *s, int n)
{
	int			i;
	static int	ret = 0;
	int			res;

	i = 0;
	res = 0;
	if (n == 1)
	{	
		res = ret;
		ret = 0;
		return (res);
	}
	if (!s)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
		ret++;
	}
	return (ret);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		y;
	char	*tmp;

	y = 0;
	i = 0;
	while (str[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == NULL)
		return (0);
	i--;
	while (i >= 0)
	{
		tmp[y] = str[i];
		i--;
		y++;
	}
	tmp[y] = '\0';
	free(str);
	return (tmp);
}

int	ft_count(int nb, int base)
{
	int		count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base_xx(int n, int base, int maj)
{
	char			*str;
	char			*hexa;
	unsigned int	nbr;
	int				count;

	nbr = n;
	count = ft_count(nbr, base);
	hexa = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (maj == 1)
		hexa = "0123456789ABCDEF";
	if (!str)
		return (NULL);
	count = 0;
	if (nbr < 0)
		nbr = 4294967295 - (nbr * -1);
	while (nbr > 0)
	{
		str[count] = hexa[nbr % base];
		nbr = nbr / base ;
		count++;
	}
	str[count] = '\0';
	str = ft_strrev(str);
	return (str);
}
