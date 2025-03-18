#include <iostream>

int main(int ac, char **av)
{
	int	i;
	int	j;
	
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		i = 0;
		i++;
		while (av[i] != NULL)
		{
			j = 0;
			while (av[i][j] != '\0')
			{
				std::cout << (char)toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
}