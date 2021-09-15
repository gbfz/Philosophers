#include "../includes/philo.h"

static inline int	check_if_philo_lives(t_philo *philo)
{
	int	verdict;

	pthread_mutex_lock(&philo->deathlock);
	if (philo->has_eaten_enough == 0)
		verdict = philo->death_time >= get_current_time();
	else
		verdict = 1;
	pthread_mutex_unlock(&philo->deathlock);
	return (verdict);
}

static inline int	check_if_feast_goes_on(const int count)
{
	static t_philo	*philo;
	int				i;

	if (philo == NULL)
		philo = get_philo(0);
	i = -1;
	while (++i < count)
	{
		pthread_mutex_lock(&(philo + i)->deathlock);
		if ((philo + i)->times_to_eat != 0)
		{
			pthread_mutex_unlock(&(philo + i)->deathlock);
			return (1);
		}
		pthread_mutex_unlock(&(philo + i)->deathlock);
	}
	return (0);
}

static int	maintain_simulation(void)
{
	const int	count = get_philo_count();
	int			i;

	usleep(99);
	while (0xBEEF)
	{
		if (check_if_feast_goes_on(count) == 0)
			return (feast_is_over());
		i = -1;
		while (++i < count)
			if (check_if_philo_lives(get_philo(i)) == 0)
				return (philo_has_died(i));
	}
}

static int	check_arguments_validity(int ac)
{
	const t_times	*times = get_times();
	const int		philo_count = get_philo_count();

	if (philo_count > 200)
		return (printf("Checklist says no more than 200 philosophers!\n"));
	if (ac == 6 && times->times_to_eat <= 0)
		return (printf("Garbage value(s) provided\n"));
	return ((philo_count > 0 && \
			times->death_time > 0 && \
			times->eat_time > 0 && \
			times->sleep_time > 0) || \
			!printf("Garbage value(s) provided\n"));
}

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("Incorrect arguments count\n"));
	set_philo_count(ft_atoi(av[1]));
	initialize_times_database(ac, av);
	if (check_arguments_validity(ac) != 1)
		return (1);
	initialize_forks_database();
	if (initialize_philo_database() == 1)
		return (end_simulation());
	start_simulation();
	maintain_simulation();
	end_simulation();
	return (0);
}
