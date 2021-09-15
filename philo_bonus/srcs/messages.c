#include "../includes/philo_bonus.h"

inline void	print_philo_is_eating(int index, sem_t *output)
{
	const time_t	time = timestamp();

	if (sem_wait(output) == -1)
		return ;
	++index;
	printf("[ %ld ]:%4s%-4d has taken a fork 🔱\n", time, "", index);
	printf("[ %ld ]:%4s%-4d has taken a fork 🔱\n", time, "", index);
	printf("[ %ld ]:%4s%-4d is eating 🍝\n", time, "", index);
	sem_post(output);
}

void	philo_has_died(const int index, sem_t *output)
{
	sem_wait(output);
	printf("[ %ld ]:%4s%-4d has died 💀\n", timestamp(), "", index + 1);
}

void	feast_is_over(sem_t *output)
{
	sem_wait(output);
	printf("[ %ld ]: the feast is over 🍷\n", timestamp()
		- get_times()->eat_time);
}
