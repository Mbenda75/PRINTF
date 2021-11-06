/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:35:09 by benmoham          #+#    #+#             */
/*   Updated: 2021/10/24 20:07:18 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include  <limits.h>

int		ft_printf(const char *str, ...);
int		ft_count(int nb, int base);
char	*ft_itoa_base_xx(int n , int base, int maj);
char	*ft_strrev(char *str);
int		ft_putchar(char c, int n);
int		ft_putstr(char *s, int n);
int		ft_count_unsigned_forptr(long int nb, int base);
char	*ft_itoa_base_ptr(unsigned long int n , int base);
void	ft_putnbr(int nb);
void	ft_putnbr_u(int nb);
void	print_xx(int hexa, char c);
void	print_p(void *addr);
void	print_s(char *s);
int		valeur_retour(int ret);
void	check_conv(va_list lst, const char *s1);

#endif
