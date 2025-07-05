NAME	= account

SRCS	= Account.cpp tests.cpp

HEADERS	= Account.hpp

OBJS	= $(SRCS:.cpp=.o)

CCXX	= c++

RM	= rm -f

CCXXFLAGS	= -g -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CCXX) $(CCXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CCXX) $(CCXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re