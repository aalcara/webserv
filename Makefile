NAME = webserv

SRCS = server.cpp

SDIR = src/
SRCS_DIR = $(addprefix $(SDIR), $(SRCS))
OBJS = $(SRCS:.cpp=.o)

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: $(SDIR)%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) webserv