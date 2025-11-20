NAME	= form

SRCS	= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp Intern.cpp

HEADERS	= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp

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