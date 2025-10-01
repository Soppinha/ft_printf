/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:53:52 by svaladar          #+#    #+#             */
/*   Updated: 2025/09/11 18:13:36 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long ptr);
int		ft_print_nbr(int n);
int		ft_print_usg(unsigned int n);
int		ft_print_hex(unsigned int n, int uppercase);
int		ft_print_per(void);

#endif