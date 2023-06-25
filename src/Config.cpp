#include "Config.hpp"
#include <sstream>

std::vector<std::string> get_lines(std::string file)
{
	std::ifstream			 ifs(file.c_str());
	std::vector<std::string> content;
	std::string				 buffer;

	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			std::getline(ifs, buffer);

			buffer = trim(buffer, "\t ");
			if (!buffer.empty())
			{
				content.push_back(buffer);
			}
		}
	}
	return content;
}

Config::Config(std::string file)
{
	std::vector<std::string> lines = get_lines(file);
	std::cout << lines[0] << std::endl;
	// TODO:SPLIT in SERVERS
}

Config::server Config::new_server()
{
	server server;

	server.listen_port			= 0;
	server.server_name			= "";
	server.client_max_body_size = -1;
	server.index				= std::vector<std::string>();
	server.allowed_method		= std::vector<std::string>();
	server.error_page			= std::vector<std::string>();
	server.autoindex			= "";
	server.routes				= std::vector<Route>();
	server.root_dir				= "";

	return server;
}
