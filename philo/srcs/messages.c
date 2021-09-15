#include "../includes/philo.h"

inline static pthread_mutex_t	*output_mutex(void)
{
	static pthread_mutex_t	output = PTHREAD_MUTEX_INITIALIZER;

	return (&output);
}

inline void	print_message(const char *message, const int index)
{
	static pthread_mutex_t	*output;

	if (output == NULL)
		output = output_mutex();
	if (pthread_mutex_lock(output))
		return ;
	printf("[ %ld ]:%4s%-4d %s\n", timestamp(), "", index + 1, message);
	pthread_mutex_unlock(output);
}

int	philo_has_died(const int index)
{
	if (pthread_mutex_lock(output_mutex()))
		return (1);
	return (printf("[ %ld ]:%4s%-4d has died\n", timestamp(), "", index + 1));
}

int	feast_is_over(void)
{
	if (pthread_mutex_lock(output_mutex()))
		return (1);
	return (printf("[ %ld ]: the feast is over 🍷\n", timestamp()));
}

void	destroy_output_mutex(void)
{
	pthread_mutex_destroy(output_mutex());
}
