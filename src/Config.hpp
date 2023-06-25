#include "webserv.hpp"

struct Config
{
	struct server
	{
		int						 listen_port;
		std::string				 server_name;
		int						 client_max_body_size;
		std::vector<std::string> index;
		std::vector<std::string> allowed_method;
		std::vector<std::string> error_page;
		std::string				 autoindex;
		std::vector<Route>		 routes;
		std::string				 root_dir;
	};

	std::vector<server> servers_vector;

	Config(std::string file);

	server new_server();
};



