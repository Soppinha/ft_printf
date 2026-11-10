/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:02 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 18:58:58 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad(char c, int n)
{
	int	count;

	count = 0;
	while (count < n)
	{
		write(1, &c, 1);
		count++;
	}
	return (count);
}

char	*ft_utoa_base(unsigned long n, char *base, char *buf)
{
	unsigned long	blen;
	int				i;

	blen = ft_pf_strlen(base);
	i = UTOA_BUF - 1;
	buf[i] = '\0';
	if (n == 0)
		buf[--i] = '0';
	while (n != 0)
	{
		buf[--i] = base[n % blen];
		n /= blen;
	}
	return (buf + i);
}

static int	ft_emit(char *prefix, int zeros, char *digits, int len)
{
	int	count;

	count = write(1, prefix, ft_pf_strlen(prefix));
	count += ft_pad('0', zeros);
	count += write(1, digits, len);
	return (count);
}

int	ft_print_number(char *digits, char *prefix, t_format fmt)
{
	int	len;
	int	zeros;
	int	total;
	int	count;

	len = ft_pf_strlen(digits);
	if (fmt.precision == 0 && digits[0] == '0')
		len = 0;
	zeros = 0;
	if (fmt.precision > len)
		zeros = fmt.precision - len;
	total = ft_pf_strlen(prefix) + zeros + len;
	if ((fmt.flags & F_ZERO) && fmt.precision < 0 && fmt.width > total)
	{
		zeros += fmt.width - total;
		total = fmt.width;
	}
	count = 0;
	if (!(fmt.flags & F_MINUS))
		count += ft_pad(' ', fmt.width - total);
	count += ft_emit(prefix, zeros, digits, len);
	if (fmt.flags & F_MINUS)
		count += ft_pad(' ', fmt.width - total);
	return (count);
}
