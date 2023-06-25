#include "webserv.hpp"
#include "Server.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		std::cout << "Using |" << argv[1] << "| config file" << std::endl;
		// TODO: parse config file
	}
	else if (argc == 1)
	{
		std::cout << "Using defaut config" << std::endl;
		// TODO: use dafault config
	}
	else
	{
		return (1);
	}
	Server server;
	server.run_server(); 
	return (0);
}
