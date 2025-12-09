NAME	= converter

SRCS	= main.cpp ScalarConverter.cpp 

HEADERS	= ScalarConverter.hpp

OBJS	= $(SRCS:.cpp=.o)

CCXX	= g++

RM	= rm -f

CCXXFLAGS = -g -gdwarf-4 -O0 -Wall -Wextra -Werror -std=c++98 \
            -fdebug-prefix-map=/sgoinfre/goinfre/Perso/alramire=/home/alramire/sgoinfre

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
