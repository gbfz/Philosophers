#include "../includes/philo_bonus.h"

inline void	precise_usleep(time_t time)
{
	const time_t	time_to_wait_for = get_current_time() + time;

	while (get_current_time() < time_to_wait_for)
		usleep(100);
}
