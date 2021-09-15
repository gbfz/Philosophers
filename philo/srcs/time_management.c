#include "../includes/philo.h"

inline time_t	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static inline time_t	simulation_start_time_singleton(const time_t *new_val)
{
	static time_t	saved_val;

	if (saved_val == 0 && new_val)
		saved_val = *new_val;
	return (saved_val);
}

inline time_t	set_simulation_start_time(void)
{
	const time_t	current_time = get_current_time();

	return (simulation_start_time_singleton(&current_time));
}

inline time_t	get_simulation_start_time(void)
{
	return (simulation_start_time_singleton(NULL));
}

inline time_t	timestamp(void)
{
	return (get_current_time() - get_simulation_start_time());
}
