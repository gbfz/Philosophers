#include "../includes/philo.h"

inline static pthread_mutex_t	**forks_database(void)
{
	static pthread_mutex_t	*forks;

	return (&forks);
}

inline pthread_mutex_t	*get_fork(int index)
{
	return (*forks_database() + index);
}

int	initialize_forks_database(void)
{
	pthread_mutex_t	**database;
	const int		count = get_philo_count();
	int				i;

	database = forks_database();
	*database = malloc(sizeof(pthread_mutex_t) * count);
	if (*database == NULL)
		return (1);
	i = -1;
	while (++i < count)
		pthread_mutex_init(*database + i, NULL);
	return (0);
}

void	destroy_mutex_database(void)
{
	pthread_mutex_t	**database;
	const int		count = get_philo_count();
	int				i;

	database = forks_database();
	i = -1;
	while (++i < count)
		pthread_mutex_destroy(*database + i);
	free(*database);
}
