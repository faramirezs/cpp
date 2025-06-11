NAME	= zombie

SRCS	= main.cpp newZombie.cpp randomChump.cpp Zombie.cpp zombieHorde.cpp

HEADERS	= Zombie.hpp

OBJS	= $(SRCS:.cpp=.o)

CC	= c++

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re