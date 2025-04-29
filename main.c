#include "push_swap.h"

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
	get_value_init_stack(argc - 1, argv + 1);
	return (0);
}