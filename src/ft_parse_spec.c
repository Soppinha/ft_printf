/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:06 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 18:59:25 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_read_num(const char *format, int *i)
{
	int	n;

	n = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
		n = n * 10 + (format[(*i)++] - '0');
	return (n);
}

static void	ft_parse_flags(const char *format, int *i, t_format *fmt)
{
	while (format[*i] && ft_pf_strchr("-0# +", format[*i]))
	{
		if (format[*i] == '-')
			fmt->flags |= F_MINUS;
		else if (format[*i] == '0')
			fmt->flags |= F_ZERO;
		else if (format[*i] == '#')
			fmt->flags |= F_HASH;
		else if (format[*i] == ' ')
			fmt->flags |= F_SPACE;
		else if (format[*i] == '+')
			fmt->flags |= F_PLUS;
		(*i)++;
	}
	if (fmt->flags & F_MINUS)
		fmt->flags &= ~F_ZERO;
	if (fmt->flags & F_PLUS)
		fmt->flags &= ~F_SPACE;
}

void	ft_parse_spec(const char *format, int *i, t_format *fmt)
{
	fmt->flags = 0;
	fmt->width = 0;
	fmt->precision = -1;
	ft_parse_flags(format, i, fmt);
	fmt->width = ft_read_num(format, i);
	if (format[*i] == '.')
	{
		(*i)++;
		fmt->precision = ft_read_num(format, i);
	}
	fmt->type = format[*i];
}
