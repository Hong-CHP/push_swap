#include "push_swap.h"

int	is_validate_param(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if(!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	*ft_bzero(int *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		s[i++] = 0;
	return (s);
}

int ft_atoi(char *str)
{
	int nb;
	int	i;
	int flag;

	i = 0;
	nb = 0;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	return (nb * flag);
}