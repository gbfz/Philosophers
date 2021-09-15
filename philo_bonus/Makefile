NAME			:=	philo_bonus

OBJS			:=	arguments_database.o	\
					checkers.o				\
					ft_atoi.o				\
					lifecycle.o				\
					messages.o				\
					philo_bonus.o			\
					philo_count.o			\
					philo_database.o		\
					precise_usleep.o		\
					semaphore_database.o	\
					time_management.o
OBJS			:=	$(addprefix srcs/, $(OBJS))

HEADERS			:=	philo_bonus.h
HEADERS			:=	$(addprefix includes/, $(HEADERS))

COMPILER		:=	clang
CFLAGS			:=	-Wall -Wextra -Werror
OFLAGS			:=	-O3

deps 			:= $(patsubst %.o,%.d,$(OBJS))

all:			$(NAME)

$(NAME):		$(OBJS) Makefile
				$(COMPILER) $(CFLAGS) $(OBJS) -o $(NAME) 

-include		$(deps)
DEPFLAGS	 	= -MMD -MF $(@:.o=.d)

%.o:			%.c
				$(COMPILER) $(OFLAGS) $(CFLAGS) -c $< $(DEPFLAGS) -o $(<:.c=.o)

clean:
				rm -f $(OBJS) $(deps)
	

fclean:			clean 
				rm -f $(NAME)

re:				fclean all
