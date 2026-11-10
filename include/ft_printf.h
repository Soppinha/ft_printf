/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svaladar <svaladar@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:53:52 by svaladar          #+#    #+#             */
/*   Updated: 2026/11/10 18:43:03 by svaladar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define F_MINUS 1
# define F_ZERO  2
# define F_HASH  4
# define F_SPACE 8
# define F_PLUS  16

# define UTOA_BUF 32
# define BASE_DEC "0123456789"
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"

typedef struct s_format
{
	int		flags;
	int		width;
	int		precision;
	char	type;
}	t_format;

int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list *args);
void	ft_parse_spec(const char *format, int *i, t_format *fmt);

int		ft_print_char(int c, t_format fmt);
int		ft_print_str(char *str, t_format fmt);
int		ft_print_ptr(unsigned long ptr, t_format fmt);
int		ft_print_nbr(int n, t_format fmt);
int		ft_print_usg(unsigned int n, t_format fmt);
int		ft_print_hex(unsigned int n, int uppercase, t_format fmt);
int		ft_print_per(void);

int		ft_pad(char c, int n);
char	*ft_utoa_base(unsigned long n, char *base, char *buf);
int		ft_print_number(char *digits, char *prefix, t_format fmt);
size_t	ft_pf_strlen(const char *s);
char	*ft_pf_strchr(const char *s, int c);

#endif