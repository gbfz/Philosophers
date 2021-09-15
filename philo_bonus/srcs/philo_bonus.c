#include "../includes/philo_bonus.h"

static void	live(t_philo *philo)
{
	sem_t	*deathlock;

	deathlock = get_semaphores()->deathlock;
	pthread_create(&philo->thread, NULL, flourish, philo);
	pthread_detach(philo->thread);
	usleep(100);
	philo->death_time = get_current_time() + get_times()->death_time;
	while (philo->has_eaten_enough != 1)
	{
		if (check_if_philo_lives(philo->death_time, deathlock) == 0)
		{
			philo_has_died(philo->index, get_semaphores()->output);
			exit(DEAD);
		}
	}
	precise_usleep(get_times()->eat_time);
	sem_post(get_semaphores()->two_forks);
	exit(FULL);
}

static void	start_feast(t_philo *philos)
{
	const int	count = get_philo_count();
	int			i;

	set_simulation_start_time();
	i = -1;
	while (++i < count)
	{
		(philos + i)->pid = fork();
		if ((philos + i)->pid == 0)
			live(philos + i);
	}
}

static void	manage_feast(t_philo *philos)
{
	int	full_philos;
	int	status;
	int	count;

	status = 0;
	full_philos = 0;
	count = get_philo_count();
	while (status != DEAD && full_philos != count)
	{
		waitpid(0, &status, 0);
		status = WEXITSTATUS(status);
		if (status == FULL)
			full_philos++;
	}
	if (full_philos == count)
		return (feast_is_over(get_semaphores()->output));
	while (count--)
		kill((philos + count)->pid, SIGQUIT);
}

static void	end_feast(void)
{
	destroy_philo_database();
	destroy_semaphore_database();
}

int	main(int ac, char **av)
{
	t_philo	*philos;

	if (ac != 5 && ac != 6)
		return (printf("Incorrect argument count\n"));
	set_philo_count(ft_atoi(av[1]));
	initialize_times_database(ac, av);
	if (check_arguments_validity(ac) != 1)
		return (1);
	initialize_semaphore_database();
	philos = initialize_philo_database();
	start_feast(philos);
	manage_feast(philos);
	end_feast();
}
