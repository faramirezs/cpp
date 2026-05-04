NAME	= btc

SRCS	= main.cpp BitcoinExchange.cpp

HEADERS	= BitcoinExchange.hpp

OBJS	= $(SRCS:.cpp=.o)

CCXX	= g++

RM	= rm -f

CCXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CCXX) $(CCXXFLAGS) -o $(NAME) $(OBJS)
		chmod +x $(NAME)

%.o: %.cpp
		$(CCXX) $(CCXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

