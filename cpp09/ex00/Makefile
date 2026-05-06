NAME	= btc

SRCS	= main.cpp BitcoinExchange.cpp

HEADERS	= BitcoinExchange.hpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++

RM	= rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADERS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
		chmod +x $(NAME)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp $(HEADERS)
		$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

