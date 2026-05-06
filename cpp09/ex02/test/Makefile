NAME    = PmergeMe

SRCS	= main.cpp PmergeMe.cpp test.cpp

HEADERS	= PmergeMe.hpp test.hpp

OBJS	= $(SRCS:.cpp=.o)

CXX	= c++

RM	= rm -f

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
		chmod +x $(NAME)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

