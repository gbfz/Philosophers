#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define FULL	0
# define DEAD	1

typedef struct s_philo
{
	pid_t		pid;
	pthread_t	thread;
	int			index;
	time_t		death_time;
	int			times_to_eat;
	int			has_eaten_enough;
}	t_philo;

typedef struct s_semaphores
{
	sem_t	*two_forks;
	sem_t	*deathlock;
	sem_t	*output;
}	t_semaphores;

typedef struct s_times
{
	int	eat_time;
	int	death_time;
	int	sleep_time;
	int	times_to_eat;
}	t_times;	

//	PHILOSOPHERS
t_philo			*initialize_philo_database(void);
t_philo			*get_philo(int index);
t_philo			*get_philos(void);
int				set_philo_count(int count);
int				get_philo_count(void);
void			destroy_philo_database(void);

//	SEMAPHORES
t_semaphores	*initialize_semaphore_database(void);
t_semaphores	*get_semaphores(void);
void			destroy_semaphore_database(void);

//	TIME
time_t			set_simulation_start_time(void);
time_t			get_simulation_start_time(void);
time_t			get_current_time(void);
time_t			timestamp(void);
void			precise_usleep(time_t time);
t_times			*initialize_times_database(int ac, char **av);
t_times			*get_times(void);

//	SIMULATION
void			*flourish(void *__philo__);
int				check_if_philo_lives(const time_t death_time, sem_t *deathlock);

//	MESSAGES
void			print_philo_is_eating(int index, sem_t *output);
void			philo_has_died(const int index, sem_t *output);
void			feast_is_over(sem_t *output);

//	Meh
int				ft_atoi(const char *s);
int				check_arguments_validity(int ac);

#endif
