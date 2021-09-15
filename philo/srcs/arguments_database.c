#include "../includes/philo.h"

static inline t_times	*times_database(void)
{
	static t_times	times;

	return (&times);
}

inline t_times	*get_times(void)
{
	return (times_database());
}

void	initialize_times_database(int ac, char **av)
{
	t_times		*database;
	static int	visited;

	database = get_times();
	if (visited == 1)
		return ;
	database->death_time = ft_atoi(av[2]);
	database->eat_time = ft_atoi(av[3]);
	database->sleep_time = ft_atoi(av[4]);
	database->times_to_eat = -1;
	if (ac == 6)
		database->times_to_eat = ft_atoi(av[5]);
	visited = 1;
}
