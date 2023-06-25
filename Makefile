NAME = webserv

SRCS = main.cpp Server.cpp Config.cpp utils.cpp

HEADERS = src/webserv.hpp

SDIR = src/
SRCS_DIR = $(addprefix $(SDIR), $(SRCS))
OBJS = $(SRCS:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -g

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: $(SDIR)%.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) webserv

re: fclean all

.PHONY: all clean fclean re