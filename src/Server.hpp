#ifndef SERVER_HPP
#define SERVER_HPP

#include "webserv.hpp"

class Server
{
public:
	Server();
	~Server();
	int run_server();
};

#endif