#include "../includes/philo.h"

static inline int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s)
{
	int	result;
	int	sign;

	sign = 1;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	result = 0;
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - 48);
	return (result * sign);
}
