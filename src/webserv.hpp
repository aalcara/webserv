#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <istream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#define PORT 8080

struct Route
{
	std::vector<std::string> allow_methods;
	std::string				 root;
	std::string				 index;
	std::vector<std::string> cgi;
	std::string				 location_dir;
	int						 client_max_body_size;
	std::vector<std::string> http_redirection;
	std::string				 autoindex;
};


// UTILS

std::string trim(const std::string &s, std::string remove);
std::string ltrim(const std::string &s, std::string remove);
std::string rtrim(const std::string &s, std::string remove);

#endif
