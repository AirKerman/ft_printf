SRCS			=	ft_printf.c ft_printf_parser.c ft_printf_error.c \
					ft_prints.c ft_printpe.c ft_printc.c ft_printd.c \
					ft_printp.c ft_printu.c ft_printx.c ft_printf_utils.c
OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
