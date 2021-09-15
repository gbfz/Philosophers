#include "../includes/philo.h"

static inline void	eat(t_philo *philo, const t_times *times, const int count)
{
	philo->take_forks(philo, count);
	pthread_mutex_lock(&philo->deathlock);
	philo->death_time = get_current_time() + times->death_time;
	if (--philo->times_to_eat == 0)
		philo->has_eaten_enough = 1;
	pthread_mutex_unlock(&philo->deathlock);
	print_message("is eating 🍝", philo->index);
	precise_usleep(times->eat_time);
	philo->drop_forks(philo, count);
}

static inline void	rest(t_philo *philo, const t_times *times)
{
	print_message("is sleeping 😴", philo->index);
	precise_usleep(times->sleep_time);
}

static inline void	think(t_philo *philo)
{
	print_message("is thinking 🤔", philo->index);
}

inline void	*live_as_even(void *__philo__)
{
	t_philo			*philo;
	const t_times	*times = get_times();
	const int		philo_count = get_philo_count();

	usleep(50);
	philo = (t_philo *)__philo__;
	while (0x0dead)
	{
		eat(philo, times, philo_count);
		if (philo->has_eaten_enough)
			return (NULL);
		rest(philo, times);
		think(philo);
	}
}

inline void	*live_as_odd(void *__philo__)
{
	t_philo			*philo;
	const t_times	*times = get_times();
	const int		philo_count = get_philo_count();

	philo = (t_philo *)__philo__;
	while (0x0dead)
	{
		eat(philo, times, philo_count);
		if (philo->has_eaten_enough)
			return (NULL);
		rest(philo, times);
		think(philo);
	}
}
