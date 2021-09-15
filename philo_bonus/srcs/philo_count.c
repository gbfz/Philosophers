#include "../includes/philo_bonus.h"

static int	philo_count_database(int *new_val)
{
	static int	saved_val;

	if (saved_val == 0 && new_val)
		saved_val = *new_val;
	return (saved_val);
}

inline int	set_philo_count(int count)
{
	return (philo_count_database(&count));
}

inline int	get_philo_count(void)
{
	return (philo_count_database(NULL));
}
