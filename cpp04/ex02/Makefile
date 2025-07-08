NAME	= abs

SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp Wanimal.cpp Wcat.cpp Brain.cpp

HEADERS	= Animal.hpp Dog.hpp Cat.hpp Wanimal.hpp Wcat.hpp Brain.hpp

OBJS	= $(SRCS:.cpp=.o)

CCXX	= c++

RM	= rm -f

CCXXFLAGS	= -g -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

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
