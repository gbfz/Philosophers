#include "../includes/philo_bonus.h"

static inline void	eat(t_philo *philo,
						const t_semaphores *semaphores,
						const t_times *times)
{
	sem_wait(semaphores->two_forks);
	sem_wait(semaphores->deathlock);
	philo->death_time = get_current_time() + times->death_time;
	if (--philo->times_to_eat == 0)
		philo->has_eaten_enough = 1;
	sem_post(semaphores->deathlock);
	print_philo_is_eating(philo->index, semaphores->output);
	precise_usleep(times->eat_time);
	sem_post(semaphores->two_forks);
}

static inline void	rest(const int index,
							sem_t *output,
							const int sleep_time)
{
	if (sem_wait(output) == -1)
		return ;
	printf("[ %ld ]:%4s%-4d is sleeping 😴\n", timestamp(), "", index + 1);
	sem_post(output);
	precise_usleep(sleep_time);
}

static inline void	think(const int index, sem_t *output)
{
	if (sem_wait(output) == -1)
		return ;
	printf("[ %ld ]:%4s%-4d is thinking 🤔\n", timestamp(), "", index + 1);
	sem_post(output);
}

inline void	*flourish(void *__philo__)
{
	t_philo				*philo;
	const t_semaphores	*semaphores = get_semaphores();
	const t_times		*times = get_times();

	philo = (t_philo *)__philo__;
	while (0xBEEF)
	{
		eat(philo, semaphores, times);
		if (philo->has_eaten_enough == 1)
			return (NULL);
		rest(philo->index, semaphores->output, times->sleep_time);
		think(philo->index, semaphores->output);
	}
}
