#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	deathlock;
	int				index;
	time_t			death_time;
	int				times_to_eat;
	int				has_eaten_enough;
	void			(*take_forks)(struct s_philo *, int);
	void			(*drop_forks)(struct s_philo *, int);
}	t_philo;

typedef struct s_times
{
	int	death_time;
	int	eat_time;
	int	sleep_time;
	int	times_to_eat;
}	t_times;

//	MUTEX DATABASE
int				initialize_forks_database(void);
void			destroy_mutex_database(void);
pthread_mutex_t	*get_fork(int index);

//	PHILOSOPHERS
int				initialize_philo_database(void);
t_philo			*get_philo(int index);
void			set_philo_count(int count);
int				get_philo_count(void);
void			take_forks_as_even(t_philo *philo, int count);
void			take_forks_as_odd(t_philo *philo, int count);
void			destroy_philo_database(void);

//	LIFECYCLE
void			*live_as_even(void *__philo__);
void			take_forks_as_even(t_philo *philo, int count);
void			drop_forks_as_even(t_philo *philo, int count);
void			*live_as_odd(void *__philo__);
void			take_forks_as_odd(t_philo *philo, int count);
void			drop_forks_as_odd(t_philo *philo, int count);

//	TIME
void			initialize_times_database(int ac, char **av);
t_times			*get_times(void);
time_t			set_simulation_start_time(void);
time_t			get_simulation_start_time(void);
time_t			get_current_time(void);
time_t			timestamp(void);
void			precise_usleep(time_t time);

//	SIMULATION
int				start_simulation(void);
int				end_simulation(void);

//	MESSAGES
void			print_message(const char *message, const int index);
int				philo_has_died(const int index);
int				feast_is_over(void);
void			destroy_output_mutex(void);

//	ATOI hahah
int				ft_atoi(const char *s);

#endif
