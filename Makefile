SRCS		= main.c big_sort.c list_utils.c parse.c small_sort.c \
				sort_utils.c sort_utils_2.c sort_utils_3.c\
				transformer.c write_min.c \
				index_sort.c index_rev_sort.c gr_th_rev_sort.c gr_th_sort.c \
				last_resort_utils.c last_resort_utils_2.c

OBJS		= ${SRCS:.c=.o}

HEAD		= push_swap.h

NAME		= push_swap

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o:	%.c ${HEAD}
		${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re