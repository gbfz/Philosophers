#include "../includes/philo_bonus.h"

static inline t_semaphores	*semaphores_database(void)
{
	static t_semaphores	semaphores;

	return (&semaphores);
}

inline t_semaphores	*get_semaphores(void)
{
	return (semaphores_database());
}

inline t_semaphores	*initialize_semaphore_database(void)
{
	t_semaphores	*semaphores;

	sem_unlink("two forks");
	sem_unlink("deathlock");
	sem_unlink("output");
	semaphores = get_semaphores();
	semaphores->two_forks = sem_open("two forks",
			O_CREAT, 777, get_philo_count() / 2);
	semaphores->deathlock = sem_open("deathlock", O_CREAT, 777, 1);
	semaphores->output = sem_open("output", O_CREAT, 777, 1);
	return (semaphores);
}

inline void	destroy_semaphore_database(void)
{
	const t_semaphores	*semaphores = get_semaphores();

	sem_close(semaphores->two_forks);
	sem_close(semaphores->deathlock);
	sem_close(semaphores->output);
}
