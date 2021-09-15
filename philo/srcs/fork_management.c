#include "../includes/philo.h"

inline void	take_forks_as_even(t_philo *philo, int count)
{
	if (philo->index == 0)
		pthread_mutex_lock(get_fork(count - 1));
	else
		pthread_mutex_lock(get_fork((philo->index - 1) % count));
	print_message("has taken a fork 🔱", philo->index);
	pthread_mutex_lock(get_fork(philo->index));
	print_message("has taken a fork 🔱", philo->index);
}

inline void	take_forks_as_odd(t_philo *philo, int count)
{
	pthread_mutex_lock(get_fork(philo->index));
	print_message("has taken a fork 🔱", philo->index);
	if (philo->index == 0)
		pthread_mutex_lock(get_fork(count - 1));
	else
		pthread_mutex_lock(get_fork((philo->index - 1) % count));
	print_message("has taken a fork 🔱", philo->index);
}

inline void	drop_forks_as_even(t_philo *philo, int count)
{
	if (philo->index == 0)
		pthread_mutex_unlock(get_fork(count - 1));
	else
		pthread_mutex_unlock(get_fork((philo->index - 1) % count));
	pthread_mutex_unlock(get_fork(philo->index));
}

inline void	drop_forks_as_odd(t_philo *philo, int count)
{
	pthread_mutex_unlock(get_fork(philo->index));
	if (philo->index == 0)
		pthread_mutex_unlock(get_fork(count - 1));
	else
		pthread_mutex_unlock(get_fork((philo->index - 1) % count));
}
