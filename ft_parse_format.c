#include "ft_printf.h"

static int	ft_handle_conversion(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		count = ft_print_nbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_usg(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (c == '%')
		count = ft_print_per();
	return (count);
}

int	ft_parse_format(const char *format, va_list args)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			temp = ft_handle_conversion(format[i + 1], args);
			if (temp == -1)
				return (-1);
			count += temp;
			i += 2;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}
