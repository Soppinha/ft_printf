/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:02:50 by svaladar          #+#    #+#             */
/*   Updated: 2025/10/01 16:05:02 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n, t_format fmt)
{
	char	buf[UTOA_BUF];
	char	*prefix;
	long	nb;

	nb = n;
	prefix = "";
	if (nb < 0)
	{
		prefix = "-";
		nb = -nb;
	}
	else if (fmt.flags & F_PLUS)
		prefix = "+";
	else if (fmt.flags & F_SPACE)
		prefix = " ";
	return (ft_print_number(ft_utoa_base(nb, BASE_DEC, buf), prefix, fmt));
}
