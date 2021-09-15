#include "../includes/philo_bonus.h"

static inline t_philo	**philo_database(void)
{
	static t_philo	*philosophers;

	return (&philosophers);
}

inline t_philo	*get_philo(int index)
{
	static int	count;

	if (count == 0)
		count = get_philo_count();
	if (index >= count || index < 0)
		return (NULL);
	return (*philo_database() + index);
}

inline t_philo	*get_philos(void)
{
	return (*philo_database());
}

t_philo	*initialize_philo_database(void)
{
	t_philo			**database;
	const t_times	*times = get_times();
	const int		count = get_philo_count();
	int				i;

	database = philo_database();
	*database = malloc(sizeof(t_philo) * count);
	if (*database == NULL)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		(*database + i)->index = i;
		(*database + i)->times_to_eat = times->times_to_eat;
		(*database + i)->has_eaten_enough = 0;
	}
	return (*database);
}

void	destroy_philo_database(void)
{
	t_philo	**database;

	database = philo_database();
	free(*database);
	*database = NULL;
}
