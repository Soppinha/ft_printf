/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:31:50 by svaladar          #+#    #+#             */
/*   Updated: 2025/09/11 18:16:42 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	s_len;

	s_len = 0;
	ft_putstr_fd(s, 1);
	s_len = ft_strlen(s);
	return (s_len);
}
