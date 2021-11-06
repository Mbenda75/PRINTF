/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:33:55 by benmoham          #+#    #+#             */
/*   Updated: 2021/10/24 20:05:22 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	lst;
	int		finalret;

	i = 0;
	finalret = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			++i;
			check_conv(lst, str + i);
		}
		else
		{
			write(1, &str[i], 1);
			finalret++;
		}
		i++;
	}
	finalret = valeur_retour(finalret);
	return (finalret);
}
