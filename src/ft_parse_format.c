/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:06 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 18:59:25 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_conversion(t_format fmt, va_list *args)
{
	int	count;

	count = 0;
	if (fmt.type == 'c')
		count = ft_print_char(va_arg(*args, int), fmt);
	else if (fmt.type == 's')
		count = ft_print_str(va_arg(*args, char *), fmt);
	else if (fmt.type == 'p')
		count = ft_print_ptr(va_arg(*args, unsigned long), fmt);
	else if (fmt.type == 'd' || fmt.type == 'i')
		count = ft_print_nbr(va_arg(*args, int), fmt);
	else if (fmt.type == 'u')
		count = ft_print_usg(va_arg(*args, unsigned int), fmt);
	else if (fmt.type == 'x')
		count = ft_print_hex(va_arg(*args, unsigned int), 0, fmt);
	else if (fmt.type == 'X')
		count = ft_print_hex(va_arg(*args, unsigned int), 1, fmt);
	else if (fmt.type == '%')
		count = ft_print_per();
	return (count);
}

static int	ft_handle_percent(const char *format, int *i, va_list *args)
{
	t_format	fmt;

	(*i)++;
	ft_parse_spec(format, i, &fmt);
	if (!format[*i])
		return (0);
	return (ft_handle_conversion(fmt, args));
}

int	ft_parse_format(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			temp = ft_handle_percent(format, &i, args);
		else
			temp = write(1, &format[i], 1);
		if (temp == -1)
			return (-1);
		count += temp;
		if (!format[i])
			break ;
		i++;
	}
	return (count);
}
