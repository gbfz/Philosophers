#include "../includes/philo_bonus.h"

inline int	check_if_philo_lives(const time_t death_time, sem_t *deathlock)
{
	int	verdict;

	sem_wait(deathlock);
	verdict = death_time >= get_current_time();
	sem_post(deathlock);
	return (verdict);
}

int	check_arguments_validity(int ac)
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
