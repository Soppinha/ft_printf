#include "ft_printf.h"

static int	ft_print_udigit(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		if (ft_print_udigit(n / 10) == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	ft_putchar_fd(c, 1);
	return (0);
}

static int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_print_usg(unsigned int n)
{
	int	len;

	len = ft_unumlen(n);
	if (ft_print_udigit(n) == -1)
		return (-1);
	return (len);
}