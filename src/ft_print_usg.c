/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_usg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:03:37 by svaladar          #+#    #+#             */
/*   Updated: 2025/10/01 16:04:49 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_usg(unsigned int n, t_format fmt)
{
	char	buf[UTOA_BUF];

	return (ft_print_number(ft_utoa_base(n, BASE_DEC, buf), "", fmt));
}
