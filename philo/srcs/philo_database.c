#include "../includes/philo.h"

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

static inline void	initialize_one_philo(t_philo *philo,
											const t_times *times,
											const time_t simulation_start_time,
											const int index)
{
	static	void	(*take[2])(t_philo *, int) =
		{take_forks_as_even, take_forks_as_odd};
	static	void	(*drop[2])(t_philo *, int) =
		{drop_forks_as_even, drop_forks_as_odd};

	pthread_mutex_init(&(philo->deathlock), NULL);
	philo->take_forks = take[index % 2 != 0];
	philo->drop_forks = drop[index % 2 != 0];
	philo->index = index;
	philo->death_time = simulation_start_time + times->death_time;
	philo->times_to_eat = times->times_to_eat;
	philo->has_eaten_enough = 0;
}

int	initialize_philo_database(void)
{
	t_philo			**database;
	time_t			simulation_start_time;
	const t_times	*times = get_times();
	const int		count = get_philo_count();
	int				i;

	database = philo_database();
	*database = malloc(sizeof(t_philo) * count);
	if (*database == NULL)
		return (1);
	simulation_start_time = set_simulation_start_time();
	i = -1;
	while (++i < count)
		initialize_one_philo((*database + i), times, simulation_start_time, i);
	return (0);
}

void	destroy_philo_database(void)
{
	t_philo		**database;
	const int	count = get_philo_count();
	int			i;

	database = philo_database();
	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&(*database + i)->deathlock);
	free(*database);
	*database = NULL;
}
