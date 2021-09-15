#include "../includes/philo.h"

int	start_simulation(void)
{
	t_philo		*philo;
	void		*(*live[2])(void *philo);
	const int	count = get_philo_count();
	int			i;

	live[0] = live_as_even;
	live[1] = live_as_odd;
	philo = get_philo(0);
	i = -1;
	while (++i < count)
		pthread_create(&(philo[i].thread), NULL, live[i % 2 != 0], philo + i);
	i = -1;
	while (++i < count)
		pthread_detach((philo + i)->thread);
	return (0);
}

int	end_simulation(void)
{
	destroy_mutex_database();
	destroy_philo_database();
	destroy_output_mutex();
	return (1);
}
