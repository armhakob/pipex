NAME   		= libft.a
SRCS		= $(shell find . -name '*.c')
OBJS    	= $(SRCS:.c=.o)
INCS		= -I
RM			= rm -f
AR			= ar rcs
CC			= cc
FLAGS  		= -Wall -Wextra -Werror
HEADER		= libft.h

%.o:	%.c $(HEADER) Makefile
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
