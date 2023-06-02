
all: server

server: server.cpp
	g++ -g server.cpp -o server

fclean:
	rm -fr server