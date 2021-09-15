#include "../includes/philo.h"

static int	philo_count_database(int *new_val)
{
	static int	saved_val;

	if (saved_val == 0 && new_val)
		saved_val = *new_val;
	return (saved_val);
}

void	set_philo_count(int count)
{
	philo_count_database(&count);
}

int	get_philo_count(void)
{
	return (philo_count_database(NULL));
}
