NAME			= pipex
BUILD			= ./build
SRCDIR			= src
SRCS			= $(wildcard $(SRCDIR)/*.c)
OBJS			= $(patsubst $(SRCDIR)/%.c, $(BUILD)/%.o, $(SRCS))
INCS			= -Iincludes -ILibft
HEADER			= $(wildcard includes/*.h)
RM				= rm -rf
CC				= cc
FLAGS			= -Wall -Wextra -Werror -fsanitize=address -g
LINKERS			= -LLibft -lft


all:	$(BUILD) lib $(NAME)

$(BUILD)/%.o:	$(SRCDIR)/%.c $(HEADER) Makefile
		$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(INCS) -o $(NAME) $(LINKERS)

$(BUILD):	$(SRCDIR) $(BSRCDIR)
			@mkdir -p $@

lib:
		$(MAKE) -C Libft

clean:
		$(RM) $(BUILD)
		@make clean -C Libft

fclean:	clean
		$(RM) $(NAME)
# $(RM) $(NAME_BONUS)
		@make fclean -C Libft

re: fclean all 


.PHONY : all clean fclean re lib
