/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_printf2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:25:44 by benmoham          #+#    #+#             */
/*   Updated: 2021/10/24 19:57:07 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h> 

int	ft_count_unsigned_forptr(long int nb, int base)
{
	long int	count;

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

char	*ft_itoa_base_ptr(unsigned long int n, int base)
{
	char	*str;
	char	*hexa;
	int		count;

	count = ft_count_unsigned_forptr(n, base);
	hexa = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	count = 0;
	if (n < 0)
		n = 4294967295 - (n * -1);
	while (n > 0)
	{
		str[count] = hexa[n % base];
		n = n / base ;
		count++;
	}
	str[count] = '\0';
	str = ft_strrev(str);
	return (str);
}

void	ft_putnbr(int nb)
{
	long	nbr;

	nbr = (long)nb;
	if (nbr < 0)
	{
		ft_putchar('-', 0);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + 48, 0);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + 48, 0);
	}
}

void	ft_putnbr_u(int nb)
{
	unsigned int	nbr;

	nbr = (unsigned int)nb;
	if (nbr < 0)
	{
		ft_putchar('-', 0);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_u(nbr / 10);
		ft_putchar(nbr % 10 + 48, 0);
	}
	if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar(nbr + 48, 0);
	}
}
