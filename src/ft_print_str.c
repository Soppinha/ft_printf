/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:20 by svaladar          #+#    #+#             */
/*   Updated: 2025/10/01 16:03:21 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, t_format fmt)
{
	int	len;
	int	count;

	if (!str && fmt.precision >= 0 && fmt.precision < 6)
		str = "";
	else if (!str)
		str = "(null)";
	len = ft_pf_strlen(str);
	if (fmt.precision >= 0 && fmt.precision < len)
		len = fmt.precision;
	count = 0;
	if (!(fmt.flags & F_MINUS))
		count += ft_pad(' ', fmt.width - len);
	count += write(1, str, len);
	if (fmt.flags & F_MINUS)
		count += ft_pad(' ', fmt.width - len);
	return (count);
}
