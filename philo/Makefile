NAME			:=	philo

OBJS			:=	arguments_database.o	\
					fork_management.o		\
					ft_atoi.o				\
					lifecycle.o				\
					main.o					\
					messages.o				\
					mutex_database.o		\
					philo_count.o			\
					philo_database.o		\
					precise_usleep.o		\
					start_end_simulation.o	\
					time_management.o
OBJS			:=	$(addprefix srcs/, $(OBJS))

HEADERS			:=	philo.h
HEADERS			:=	$(addprefix includes/, $(HEADERS))

COMPILER		:=	clang
CFLAGS			:=	-Wall -Wextra -Werror
OFLAGS			:=	-O3

deps 			:= $(patsubst %.o,%.d,$(OBJS))

all:			$(NAME) Makefile

$(NAME):		$(OBJS) Makefile
				$(COMPILER) $(OFLAGS) $(CFLAGS) $(OBJS) -o $(NAME) 

-include		$(deps)
DEPFLAGS	 	= -MMD -MF $(@:.o=.d)

%.o:			%.c
				$(COMPILER) $(OFLAGS) $(CFLAGS) -c $< $(DEPFLAGS) -o $(<:.c=.o)

clean:
				rm -f $(OBJS) $(deps)

fclean:			clean 
				rm -f $(NAME)

re:				fclean all
