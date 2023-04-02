/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwee <lwee@student.42adel.org.au>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:23:02 by lwee              #+#    #+#             */
/*   Updated: 2023/04/02 19:23:02 by lwee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

struct	s_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		t1;
	int				id;
	unsigned long	time_to_die;
	int				meals_eaten;
	int				eating;
	int				status;
	pthread_mutex_t	lock;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_philo;

typedef struct s_data
{
	pthread_t		*tid;
	int				philo_nb;
	int				meals_nb;
	int				dead;
	int				done;
	t_philo			*philos;
	unsigned long	death_time;
	unsigned long	eat_time;
	unsigned long	sleep_time;
	unsigned long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	write;
}	t_data;

// init
int				init_data(t_data *data, char **argv, int argc);
int				alloc(t_data *data);
int				init_forks(t_data *data);
void			init_philos(t_data *data);
int				init(t_data *data, char **argv, int argc);

// utils
long			ft_atoi(const char *str);
int				check_input(char **argv);
int				ft_usleep(useconds_t time);
int				ft_strncmp(char *s1, char *s2);

// actions
unsigned long	get_time(void);
void			messages(char *str, t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
void			eat(t_philo *philo);

// threads
void			*monitor(void *data_pointer);
void			*supervisor(void *philo_pointer);
void			*routine(void *philo_pointer);
int				thread_init(t_data *data);

// main
int				error(char *str, t_data *data);
void			ft_exit(t_data *data);
void			clear_data(t_data *data);

#endif
