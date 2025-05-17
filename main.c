#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) *sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**reverse_params(int ac, char *av[])
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(ac * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = ac - 1;
	while (i < ac)
	{
		res[i] = ft_strdup(av[j]);
		j--;
		i++;
	}
	return (res);
}

void	split_op_params_put_stack(int ac, char *av[])
{
	// char **str_tab;
	int	index_split;

	if (ft_split_needed(ac, av))
	{
		index_split = ft_split_needed(ac, av);
		printf("index where split needed is : %d\n", index_split);
		//ft_split(av[index_split]);
	}
	// str_tab = reverse_params(ac, av);
	// get_value_init_stack(ac, str_tab);
	// i = 0;
	// while (i < ac)
	// {
	// 	free(str_tab[i]);
	// 	i++;
	// }
	// free(str_tab);
}

int main(int argc, char *argv[])
{
	int i;

	if (argc <= 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_validate_param(argv[i]))
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	split_op_params_put_stack(argc - 1, argv + 1);

	return (0);
}