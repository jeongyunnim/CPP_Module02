NAME 		=	ex02

CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

INCS		=	./Fixed.hpp\

SRCS		=	./main.cpp\
				./Fixed.cpp\

OBJS		=	$(SRCS:%.cpp=%.o)

RM			=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%o:	%.c
	$(CXX) $(CXXFLAGS) $(INCS) -c $^ -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re