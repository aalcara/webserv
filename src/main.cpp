#include "Config.hpp"
#include "Server.hpp"
#include "webserv.hpp"

int main(int argc, char **argv)
{
	std::string filename;

	if (argc == 2)
	{
		std::cout << "Using |" << argv[1] << "| config file" << std::endl;
		filename = argv[1];
	}
	else if (argc == 1)
	{
		std::cout << "Using defaut config" << std::endl;
		filename = "config/default.conf";
	}
	else
	{
		return (1);
	}
	Config config(filename);

	// Server server;
	// server.run_server();

	
	
	return (0);

	
}
