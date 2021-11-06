/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:04:59 by benmoham          #+#    #+#             */
/*   Updated: 2021/10/24 20:05:31 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_xx(int hexa, char c)
{
	char	*tmp;

	if (c == 'x')
	{
		if (hexa == 0)
			ft_putchar('0', 0);
		else
		{
			tmp = ft_itoa_base_xx(hexa, 16, 0);
			ft_putstr(tmp, 0);
			free(tmp);
		}
	}
	else if (c == 'X')
	{
		if (hexa == 0)
			ft_putchar('0', 0);
		else
		{
			tmp = ft_itoa_base_xx(hexa, 16, 1);
			ft_putstr(tmp, 0);
			free(tmp);
		}
	}
}

void	print_p(void *addr)
{
	char	*tmp;

	if (addr == 0)
		ft_putstr("0x0", 0);
	else
		ft_putstr("0x", 0);
	tmp = ft_itoa_base_ptr((intptr_t)addr, 16);
	ft_putstr(tmp, 0);
	free(tmp);
}

void	print_s(char *s)
{
	if (s == NULL)
		ft_putstr("(null)", 0);
	else
		ft_putstr(s, 0);
}

int	valeur_retour(int ret)
{
	int		result1;
	int		result2;

	result1 = ft_putchar('0', 1);
	result2 = ft_putstr("0", 1);
	ret = ret + result1 + result2;
	return (ret);
}

void	check_conv(va_list lst, const char *s1)
{
	int	i;

	i = 0;
	if (s1[i] == 's')
		print_s(va_arg(lst, char *));
	else if (s1[i] == 'X')
		print_xx(va_arg(lst, int), 'X');
	else if (s1[i] == 'x')
		print_xx(va_arg(lst, int), 'x');
	else if (s1[i] == 'c')
		ft_putchar(va_arg(lst, int), 0);
	else if (s1[i] == 'i' || s1[i] == 'd')
		ft_putnbr(va_arg(lst, int));
	else if (s1[i] == 'p')
		print_p(va_arg(lst, void *));
	else if (s1[i] == 'u')
		ft_putnbr_u(va_arg(lst, int));
	else if (s1[i] == '%')
		ft_putchar('%', 0);
}
