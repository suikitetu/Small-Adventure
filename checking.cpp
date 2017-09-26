#include "My_macros.h"

// We're checking if the value str is a number, or not.
int	my_check_nb(std::string str)
{
	int	i = -1;

	while (++i < str.size())
		if (str[i] < '0' || str[i] > '9')
			return (MY_ERROR);
	return (MY_SUCCESS);
}